package main

import (
	"bufio"
)
import "log"
import "github.com/tarm/serial"

func main() {
	config := &serial.Config{
		Name: "/dev/ttyACM0",
		Baud: 9600,
		//ReadTimeout: 1,
		Size: 8,
	}

	stream, err := serial.OpenPort(config)
	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(stream)
	for scanner.Scan() {
		log.Println(scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}
}
