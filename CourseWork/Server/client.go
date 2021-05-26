package main

import (
	"fmt"
	"log"
	"net"
	"strings"
	"unicode/utf8"
)

type client struct {
	conn     net.Conn
	nick     string
	room     *room
	commands chan<- command
}

func (c *client) readInput() {
	for {
		input := make([]byte, (1024 * 4))
		n, err := c.conn.Read(input) // считываение сообщения
		if err != nil {
			return
		}
		str := ""
		for i := 0; i < n; i++ {
			r, size := utf8.DecodeRune(input) // перевод в кодировку utf-8
			str = str + string(r)
			input = input[size:]
		}
		log.Printf("%s", str)
		str = strings.Trim(str, "\r\n")
		args := strings.Split(str, " ")
		cmd := strings.TrimSpace(args[0])
		switch cmd {
		case "n":
			c.commands <- command{
				id:     CMD_N,
				client: c,
				args:   args,
			}
		case "j":
			c.commands <- command{
				id:     CMD_J,
				client: c,
				args:   args,
			}
		case "r":
			c.commands <- command{
				id:     CMD_R,
				client: c,
			}
		case "m":
			c.commands <- command{
				id:     CMD_M,
				client: c,
				args:   args,
			}
		case "q":
			c.commands <- command{
				id:     CMD_Q,
				client: c,
			}
		default:
			c.err(fmt.Errorf("unknown command: %s", cmd))
		}
	}
}

func (c *client) err(err error) {
	c.conn.Write([]byte("err: " + err.Error() + "\n"))
}

func (c *client) msg(msg string) {
	c.conn.Write([]byte(msg))
}
