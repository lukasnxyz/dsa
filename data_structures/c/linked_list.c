#include <stdio.h>

typedef struct {
    char letter;
    struct List *next;
} List;

/*
 * size() - returns number of data elements in list
 * empty() - bool returns true if empty
 * value_at(index) - returns the value of the nth item (starting at 0 for first)
 * add_front(value) - adds an item to the front of the list
 * add_back(value) - adds an item at the end
 * pop_front() - remove front item and return its value
 * pop_back() - removes end item and returns its value
 * front() - get value of front item
 * back() - get value of end item
 * insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
 * erase(index) - removes node at given index
 * value_n_from_end(n) - returns the value of the node at nth position from the end of the list
 * reverse() - reverses the list
 * remove_value(value) - removes the first item in the list with this value
*/

int main() {

    return 0;
}
