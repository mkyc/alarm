package main

import (
	"log"
	"net"
	"os"
	"strconv"
	"strings"
	"time"
)

const socketAddr = "/tmp/pub.sock"

var connections []net.Conn
var counter = 1

func send() {
	for {
		data := []byte(strconv.Itoa(counter))
		log.Println("send()")
		i := 0
		for _, c := range connections {
			log.Printf("will write: %v to %s\n", string(data), c.LocalAddr())
			_, err := c.Write(data)
			if err != nil {
				if strings.HasSuffix(err.Error(), "broken pipe") {
					log.Println("I got broken pipe")
					continue
				} else {
					log.Fatal("Write: ", err)
				}
			}
			connections[i] = c
			i++
		}
		for j := i; j < len(connections); j++ {
			connections[j] = nil
		}
		connections = connections[:i]
		counter++
		time.Sleep(2 * time.Second)
	}
}

func add(c net.Conn) {
	log.Println("add()")
	if connections == nil {
		connections = make([]net.Conn, 0, 0)
	}
	connections = append(connections, c)
}

func main() {
	if err := os.RemoveAll(socketAddr); err != nil {
		log.Fatal(err)
	}

	l, err := net.Listen("unix", socketAddr)
	if err != nil {
		log.Fatal("listen error:", err)
	}

	go send()

	for {
		fd, err := l.Accept()
		if err != nil {
			log.Fatal("accept error:", err)
		}

		add(fd)
	}
}
