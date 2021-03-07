package main

import (
	"bufio"
	"runtime"
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
		printMemUsage()
	}
	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}
}

func printMemUsage() {
	var m runtime.MemStats
	runtime.ReadMemStats(&m)
	log.Printf("Alloc = %v KiB, TotalAlloc = %v KiB, Sys = %v KiB, NumGC = %v\n", bToKb(m.Alloc), bToKb(m.TotalAlloc), bToKb(m.Sys), m.NumGC)
}

func bToKb(b uint64) uint64 {
	return b / 1024
}
