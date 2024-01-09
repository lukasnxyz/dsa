package main

import (
    "fmt"
)

type Node struct {
    x int
    next *Node
}

func (head *Node) Append(x int) {
    new_node := &Node{x, nil}

    if head == nil {
        head = new_node
        return
    }

    tmp := head

    for tmp.next != nil {
        tmp = tmp.next
    }

    tmp.next = new_node
}

func (head *Node) Prepend(x int) {
    if head == nil {
        new_node := &Node{x: x, next: nil}
        head = new_node

        return
    }

    new_node := &Node{x: x, next: head}
    head = new_node
}

/*
func (head *Node) Delete(x int) {
}
*/

func (head *Node) Print() {
    tmp := head

    for i := 0; tmp != nil; i++ {
        fmt.Println(i, "num:", tmp.x)
        tmp = tmp.next
    }
}

func main() {
    fmt.Println("Linked lists!")

    head := Node{0, nil}

    head.Append(1)
    head.Append(2)
    head.Append(3)
    head.Append(4)
    //head.Prepend(-1)

    head.Print()
}
