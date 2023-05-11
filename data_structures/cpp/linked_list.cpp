#include <iostream>

class Node {
    private:
        int data;
    public:
        Node *next;

        // default constructor
        Node() {
            data = 0;
            next = NULL;
        }

        // paramtized constructor
        Node(int n_data) {
            this->data = n_data;
            this->next = NULL;
        }

        int getData() {
            return data;
        }
};

class LinkedList {
    private:
        Node *head;
    public:
        // default constructor
        LinkedList() {
            head = NULL;
        }

        // class functions
        void addNode(int);
        void printList();
        void deleteNode(Node *);
        Node *getHead();
};

Node *LinkedList::getHead() {
    return head;
}

void LinkedList::printList() {
    Node *tmp = head;

    // check if anything in list
    if(head == NULL) {
        return;
    }

    // go through each element and print it
    while(tmp != NULL) {
        std::cout << tmp->getData() << std::endl;
        tmp = tmp->next;
    }
}

void LinkedList::addNode(int input_data) {
    Node *newNode = new Node(input_data);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node *tmp = head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void LinkedList::deleteNode(Node *prevDel) {
    Node *del = prevDel->next;
    prevDel->next = del->next;
    delete del;
}

int main() {
    LinkedList list1;

    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);
    list1.addNode(4);
    list1.addNode(5);

    Node *tmp = list1.getHead();
    list1.deleteNode(tmp);

    list1.printList();

    return 0;
}
