package main

type commandID int

const (
	CMD_N commandID = iota
	CMD_J
	CMD_R
	CMD_M
	CMD_Q
)

type command struct {
	id     commandID
	client *client
	args   []string
}
