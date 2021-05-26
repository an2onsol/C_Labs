package main

import (
	"log"
	"net"
)

func main() {
	port := ":8888"
	//запуск сервера
	s := newServer()
	go s.run()
	listener, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("unable to start server: %s", err.Error())
	}
	defer listener.Close()
	log.Printf("server started on " + port)
	for {
		//подключение пользователя
		conn, err := listener.Accept()
		if err != nil {
			log.Printf("failed to accept connection: %s", err.Error())
			continue
		}
		go s.newClient(conn)
	}
}
