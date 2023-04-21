#include "linkedList.h"

// default constructor
LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// console printing
void LinkedList::print() {
    if (this->head != nullptr) {
        Node *cur = head;
        while (cur != nullptr) {
            std::cout << cur->value << ' ';
            cur = cur->next;
        }
        std::cout << std::endl;
    } else {
        std::cout << "Nothing to print. List is empty!" << std::endl;
    }
}

// add element in the end
void LinkedList::push_back(int value) {
    if (head == nullptr) {
        this->head = new Node(value, nullptr);
        this->tail = head;
    } else {
        this->tail->next = new Node(value, nullptr);
        tail = tail->next;
    }
    this->size++;
}

// add element in the beginning
void LinkedList::push_front(int value) {
    Node *newHead = new Node(value, this->head);
    if (this->head == nullptr) {
        this->tail = newHead;
    }
    this->head = newHead;
    this->size++;
}

// add element by index
void LinkedList::push_index(int index, int value) {
    if (index < 0 || index > this->size) {
        std::cout << "Given index out of list borders" << std::endl;
    } else if (index == 0) {
        push_front(value);
    } else if (index == this->size) {
        push_back(value);
    } else {
        Node *cur = head;
        int cur_index = 0;
        while (cur_index + 1 != index) {
            cur = cur->next;
            cur_index++;
        }
        cur->next = new Node(value, cur->next);
        this->size++;
    }
}

// delete element from the end
void LinkedList::pop_back() {
    if (head != nullptr) {
        Node *cur = head, *prev = nullptr;
        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;
        }
        tail = prev;
        this->size--;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        delete cur;
        if (this->size == 0) {
            head = nullptr;
        }
    } else {
        std::cout << "Nothing to pop. List is empty!" << std::endl;
    }
}

// delete element from the beginning
void LinkedList::pop_front() {
    if (head != nullptr) {
        Node *cur = head;
        this->head = head->next;
        this->size--;

        cur->next = nullptr;
        delete cur;
    } else {
        std::cout << "Nothing to pop. List is empty!" << std::endl;
    }
}

// delete all elements with given value
void LinkedList::pop_value(int value) {
    if (this->head != nullptr) {
        Node *cur = head, *prev = nullptr;
        while (cur != nullptr) {
            if (cur->value == value) {
                if (prev != nullptr) {
                    prev->next = cur->next;
                    cur->next = nullptr;
                    delete cur;
                    cur = prev->next;
                } else {
                    this->head = cur->next;
                    cur->next = nullptr;
                    delete cur;
                    cur = head;
                }
                this->size--;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        this->tail = prev;
    } else {
        std::cout << "Nothing to pop. List is empty!" << std::endl;
    }
}

// delete element by index
void LinkedList::pop_index(int index) {
    if (head == nullptr) {
        std::cout << "Nothing to pop. List is empty!" << std::endl;
    } else if (index < 0 || index >= this->size) {
        std::cout << "Given index out of list borders" << std::endl;
    } else if (index == 0) {
        pop_front();
    } else {
        Node *cur = head;
        int cur_index = 0;
        while (cur_index + 1 != index) {
            cur = cur->next;
            cur_index++;
        }
        Node *deleted = cur->next;
        cur->next = deleted->next;

        deleted->next = nullptr;
        delete deleted;

        if (cur_index == this->size - 2) {
            this->tail = cur;
        }
        this->size--;
    }
}

// returns first position of element, -1 if not found
int LinkedList::find_value(int value) {
    int cur_index = 0;
    Node *cur = head;
    while (cur != nullptr) {
        if (cur->value == value) {
            return cur_index;
        } else {
            cur = cur->next;
            cur_index++;
        }
    }
    return -1;
}

// returns true if element at index == value, else returns false
bool LinkedList::find_at_index(int index, int value) {
    if (index < 0 || index >= this->size) {
        std::cout << "Given index out of list borders!" << std::endl;
        return false;
    } else {
        int cur_ind = 0;
        Node *cur = head;
        while (cur_ind != index) {
            cur_ind++;
            cur = cur->next;
        }
        return cur->value == value;
    }
}

// delete all elements from the list
void LinkedList::clear() {
    delete head;
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// list destructor
LinkedList::~LinkedList() {
    delete head;
}

// node default constructor
LinkedList::Node::Node() {
    this->value = 0;
    this->next = nullptr;
}

// node arguments constructor
LinkedList::Node::Node(int value, Node* next) {
    this->value = value;
    this->next = next;
}

// node destructor
LinkedList::Node::~Node() {
    delete next;
}
