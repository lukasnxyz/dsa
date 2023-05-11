#include <iostream>

// size of hashtable array
#define HASHMAX 100

class Node {
    std::string name;
    public:
        Node *next;

        Node() {
            name = "name";
            next = NULL;
        }

        Node(std::string n_name) {
            name = n_name;
            next = NULL;
        }

        std::string getName() {
            return name;
        }
};

class LinkedList {
    Node *head;
    public:
        LinkedList() {
            head = NULL;
        }

        void addToEnd(std::string);
        void printList();

        Node *getHead() {
            return head;
        }
};

LinkedList **hashArr = new LinkedList*[HASHMAX]; /* <- create an array of pointers of type LinkedList (everything after equals) */
/* ^ pointer to array of pointers for hashtable (everything before equals) */

std::string namesList[HASHMAX] = {"Olivia", "Liam", "Emma", "Noah", "Amelia", "Oliver", "Ava", "Elijah", "Sophia", "Mateo", "Isabella", "Lucas", "Luna", "Levi", "Mia", "Asher", "Charlotte", "James", "Evelyn", "Leo", "Harper", "Grayson", "Scarlett", "Ezra", "Nova", "Luca", "Aurora", "Ethan", "Ella", "Aiden", "Mila", "Wyatt", "Aria", "Sebastian", "Ellie", "Benjamin", "Gianna", "Mason", "Sofia", "Henry", "Violet", "Hudson", "Layla", "Jack", "Willow", "Jackson", "Lily", "Owen", "Hazel", "Daniel", "Camila", "Alexander", "Avery", "Maverick", "Chloe", "Kai", "Elena", "Gabriel", "Paisley", "Carter", "Eliana", "William", "Penelope", "Logan", "Eleanor", "Michael", "Ivy", "Samuel", "Elizabeth", "Muhammad", "Riley", "Waylon", "Isla", "Ezekiel", "Abigail", "Jayden", "Nora", "Luke", "Stella", "Lincoln", "Grace", "Theo", "Zoey", "Jacob", "Emily", "Josiah", "Emilia", "David", "Leilani", "Jaxon", "Everly", "Elias", "Kinsley", "Julian", "Athena", "Theodore", "Delilah", "Isaiah", "Naomi", "Matthe"};

void LinkedList::addToEnd(std::string n_name) {
    Node *newNode = new Node(n_name);

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

void LinkedList::printList() {
    Node *tmp = head;

    while(tmp != NULL) {
        std::cout << "\"" << tmp->getName() << "\" " ;
        tmp = tmp->next;
    }

    std::cout << "\n" << std::endl;
}

unsigned int hashFunction(std::string name) {
    // very very simple hash function
    int sum = 0;

    for(int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }

    return sum % HASHMAX;
}

void hashSort(int hashNum, std::string name) {
    // add name to end of linked list in specific array node
    hashArr[hashNum]->addToEnd(name);
}

int main() {

    // initialize each node in hashtable
    for(int i = 0; i < HASHMAX; i++) {
        hashArr[i] = new LinkedList();
    }

    // hash function on all names from nameList
    for(int i = 0; i < HASHMAX; i++) {
        hashSort(hashFunction(namesList[i]), namesList[i]);
    }

    // print each linked list for all 10 array nodes
    for(int i = 0; i < HASHMAX; i++) {
        std::cout << i << ": ";
        hashArr[i]->printList();
    }

    return 0;
}
