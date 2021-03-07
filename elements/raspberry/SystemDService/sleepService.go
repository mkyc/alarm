package main

import (
	"flag"
	"log"
	"math/rand"
	"os"
	"os/signal"
	"syscall"
	"time"
)

// based on https://fabianlee.org/2017/05/21/golang-running-a-go-binary-as-a-systemd-service-on-ubuntu-16-04/
// modified using https://ofstack.com/Golang/24886/golang-signal-processing-and-how-to-implement-a-process-exit-gracefully-detail.html

func main() {

	// load command line arguments
	name := flag.String("name", "world", "name to print")
	flag.Parse()

	log.Printf("Starting sleepservice for %s", *name)

	// setup signal catching
	signals := make(chan os.Signal, 1)

	// catch all signals since not explicitly listing
	signal.Notify(signals)
	//signal.Notify(signals, syscall.SIGINT, syscall.SIGTERM, syscall.SIGHUP, syscall.SIGQUIT)

	//// method invoked upon seeing signal
	//go func() {
	//	s := <-signals
	//	log.Printf("RECEIVED SIGNAL: %s", s)
	//
	//	switch s {
	//	case syscall.SIGINT, syscall.SIGTERM, syscall.SIGHUP, syscall.SIGQUIT:
	//		appCleanup()
	//		os.Exit(1)
	//	default:
	//		log.Printf("not used signal: %s", s)
	//	}
	//}()

	go func() {
		for s := range signals {
			log.Printf("RECEIVED SIGNAL: %s", s)

			switch s {
			case syscall.SIGINT, syscall.SIGTERM, syscall.SIGHUP, syscall.SIGQUIT:
				appCleanup()
				os.Exit(0)
			default:
				log.Printf("not used signal: %s", s)
			}
		}
	}()

	// infinite print loop
	for {
		log.Printf("hello %s", *name)

		// wait random number of milliseconds
		n := rand.Intn(3000) + 1000
		log.Printf("About to sleep %dms before looping again", n)
		time.Sleep(time.Millisecond * time.Duration(n))
	}

}

func appCleanup() {
	log.Println("CLEANUP APP BEFORE EXIT!!!")
}
