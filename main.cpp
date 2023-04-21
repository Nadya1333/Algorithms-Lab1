#include "linkedList.h"
#include <string>

void printHelpMenu() {
    std::cout << "Commands:"                                                << std::endl <<
                 "help              : to get help"                          << std::endl <<
                 "print             : to print list in console"             << std::endl <<
                 "pushb <value>     : to push element at the end"           << std::endl <<
                 "pushf <value>     : to push element at the beginning"     << std::endl <<
                 "pushi <ind> <val> : to push element by index"             << std::endl <<
                 "popb              : to pop element from the end"          << std::endl <<
                 "popf              : to pop element from the beginning"    << std::endl <<
                 "popv <value>      : to pop elements by value"             << std::endl <<
                 "popi <index>      : to pop element by index"              << std::endl <<
                 "findVal <value>   : to find first index of value in list" << std::endl <<
                 "findAt <index> <value> : to check element at index"       << std::endl <<
                 "clear             : to delete all elements in the list"   << std::endl <<
                 "exit              : to exit"                              << std::endl;
}

int main() {
    int index, value;
    LinkedList list;
    printHelpMenu();

    std::string command;
    std::cin >> command;
    while (command != "exit") {
        if (command == "print") {
            list.print();
        } else if (command == "pushb") {
            std::cin >> value;
            list.push_back(value);
            std::cout << "OK" << std::endl;
        } else if (command == "pushf") {
            std::cin >> value;
            list.push_front(value);
            std::cout << "OK" << std::endl;
        } else if (command == "pushi") {
            std::cin >> index >> value;
            list.push_index(index, value);
            std::cout << "OK" << std::endl;
        } else if (command == "popb") {
            list.pop_back();
            std::cout << "OK" << std::endl;
        } else if (command == "popf") {
            list.pop_front();
            std::cout << "OK" << std::endl;
        } else if (command == "popv") {
            std::cin >> value;
            list.pop_value(value);
            std::cout << "OK" << std::endl;
        } else if (command == "popi") {
            std::cin >> index;
            list.pop_index(index);
            std::cout << "OK" << std::endl;
        } else if (command == "findVal") {
            std::cin >> value;
            // "First index of <value> = -1" means that no such value in the list
            std::cout << "First index of " << value << " = " << list.find_value(value) << std::endl;
        } else if (command == "findAt") {
            std::cin >> index >> value;
            std::cout << (list.find_at_index(index, value) ? "true" : "false") << std::endl;
        } else if (command == "clear") {
            list.clear();
            std::cout << "OK" << std::endl;
        } else if (command == "help") {
            printHelpMenu();
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command" << std::endl;
        }
        std::cin >> command;
    }

    return 0;
}
