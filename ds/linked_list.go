package main

import (
    "fmt"
)

type Node struct {
    x int
    next *Node
}

func (head *Node) Append(x int) {
    newNode := &Node{x, nil}

    if head == nil {
        head = newNode

        return
    }

    tmp := head

    for tmp.next != nil {
        tmp = tmp.next
    }

    tmp.next = newNode
}

func (head *Node) Prepend(x int) (*Node) {
    newNode := &Node{x, nil}
    if head == nil {
        head = newNode
        return head
    }

    newNode.next = head
    head = newNode

    return head
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

    head := &Node{}

    head.Append(1)
    head.Append(2)
    head.Append(3)
    head.Append(4)

    head = head.Prepend(-1)

    head.Print()
}

/*
package main

import "fmt"

type List struct {
    x    int
    next *List
}

func NewList(x int, next *List) *List {
    return &List{x, next}
}

func (l *List) Append(x int) {
    now := l
    for ; now.next != nil; now = now.next {
    }

    now.next = NewList(x, nil)
}

func (l *List) Prepend(x int) *List {
    return NewList(x, l)
}

func (l *List) Print() {
    for now := l; now != nil; now = now.next {
        fmt.Printf("%d -> ", now.x)
    }

    fmt.Printf("nil\n")
}

func main() {
    list := NewList(5, nil)
    list.Append(6)
    list.Append(7)
    list.Print()
    list = list.Prepend(4)
    list.Print()
}*/
