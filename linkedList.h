#ifndef ALGO_LAB1_LINKED_LIST_H
#define ALGO_LAB1_LINKED_LIST_H
#include <initializer_list>
#include <iostream>

class LinkedList {
public:
    LinkedList();       // default constructor
    ~LinkedList();      // list destructor

    // Methods
    void print();                   // console output
    void push_back(int value);      // add element in the end
    void push_front(int value);     // add element in the beginning
    void push_index(int index, int value);    // add element by index
    void pop_back();                // delete element from the end
    void pop_front();               // delete element from the beginning
    void pop_value(int value);      // delete all elements with given value
    void pop_index(int index);      // delete element by index
    int find_value(int value);      // returns first position of element, -1 if not found
    bool find_at_index(int index, int value); // returns true if element at index == value, else returns false
    void clear();                   // delete all elements from the list

private:
    struct Node {
        int value;  // value of element
        Node *next; // pointer to next element

        Node();     // node default constructor
        Node(int value, Node* next);    // node arguments constructor
        ~Node();    // node destructor
    };

    Node *head;     // pointer to head of list
    Node *tail;     // pointer to end of list
    size_t size;    // length of list
};

#endif //ALGO_LAB1_LINKED_LIST_H
