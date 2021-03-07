package main

import (
	"io"
	"net"
)

const socketAddr = "/tmp/pub.sock"

func reader(r io.Reader) {
	buf := make([]byte, 1024)
	for {
		n, err := r.Read(buf[:])
		if err != nil {
			return
		}
		println("Client got:", string(buf[0:n]))
	}
}

func main() {
	c, err := net.Dial("unix", socketAddr)
	if err != nil {
		panic(err)
	}
	defer c.Close()

	go reader(c)
	select {}
}
