#include "linkedList.h"
#include <string>

void printHelpMenu() {
    std::cout << "Commands:"                                      << std::endl <<
                 "help       : to get help"                       << std::endl <<
                 "print      : to print list in console"          << std::endl <<
                 "push back  : to push element at the end"        << std::endl <<
                 "push front : to push element at the beginning"  << std::endl <<
                 "push index : to push index by index"            << std::endl <<
                 "pop back   : to pop element from the end"       << std::endl <<
                 "pop front  : to pop element from the beginning" << std::endl <<
                 "pop value  : to pop elements by value"          << std::endl <<
                 "pop index  : to pop element by index"           << std::endl <<
                 "find value : to find index of value in list"    << std::endl <<
                 "find at    : to check element at index"         << std::endl <<
                 "exit       : to exit"                           << std::endl;
}

int main() {
    int index, value;
    LinkedList list;
    printHelpMenu();

    std::string command;
    while (true) {
        std::getline(std::cin, command);
        if (command == "print") {
            list.print();
        } else if (command == "push back") {
            std::cout << "Input value to push: " << std::endl;
            std::cin >> value;
            list.push_back(value);
            std::cout << "OK" << std::endl;
        } else if (command == "push front") {
            std::cout << "Input value to push: " << std::endl;
            std::cin >> value;
            list.push_front(value);
            std::cout << "OK" << std::endl;
        } else if (command == "push index") {
            std::cout << "Input <index> <value> to push: " << std::endl;
            std::cin >> index >> value;
            list.push_index(index, value);
            std::cout << "OK" << std::endl;
        } else if (command == "pop back") {
            list.pop_back();
            std::cout << "OK" << std::endl;
        } else if (command == "pop front") {
            list.pop_front();
            std::cout << "OK" << std::endl;
        } else if (command == "pop value") {
            std::cout << "Input value to pop: " << std::endl;
            std::cin >> value;
            list.pop_value(value);
            std::cout << "OK" << std::endl;
        } else if (command == "pop index") {
            std::cout << "Input index to pop: " << std::endl;
            std::cin >> index;
            list.pop_index(index);
            std::cout << "OK" << std::endl;
        } else if (command == "find value") {
            std::cout << "Input value to find: " << std::endl;
            std::cin >> value;
            // "First index of <value> = -1" means that no such value in the list
            std::cout << "First index of " << value << " = " << list.find_value(value) << std::endl;
        } else if (command == "find at") {
            std::cout << "Input <index> <value> to find value at index: " << std::endl;
            std::cin >> index >> value;
            std::cout << (list.find_at_index(index, value) == 1 ? "true" : "false") << std::endl;
        } else if (command == "help") {
            printHelpMenu();
        } else if (command == "exit") {
            break;
        }
    }

    return 0;
}
