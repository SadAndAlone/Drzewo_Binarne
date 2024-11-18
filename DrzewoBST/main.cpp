#include <iostream>
#include "BST.h"
#include "FileManager.h"

void menu() {
    std::cout << "1. Insert Element\n";
    std::cout << "2. Remove Element\n";
    std::cout << "3. Print Tree\n";
    std::cout << "4. Save Tree to File\n";
    std::cout << "5. Load Tree from File\n";
    std::cout << "6. Exit\n";
}

int main() {
    BST tree;
    int choice;

    while (true) {
        menu();
        std::cin >> choice;

        if (choice == 1) {
            int value;
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            tree.insert(value);
        }
        else if (choice == 2) {
            int value;
            std::cout << "Enter value to remove: ";
            std::cin >> value;
            tree.remove(value);
        }
        else if (choice == 3) {
            std::cout << "Choose traversal order (1- Preorder, 2- Inorder, 3- Postorder): ";
            int order;
            std::cin >> order;
            tree.printTree(order);
        }
        else if (choice == 4) {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            tree.saveToFile(filename);
        }
        else if (choice == 5) {
            std::string filename;
            std::cout << "Enter filename to load: ";
            std::cin >> filename;
            tree.loadFromFile(filename);
        }
        else if (choice == 6) {
            break;
        }
    }

    return 0;
}
