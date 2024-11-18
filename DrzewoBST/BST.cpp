#include "BST.h"
#include <iostream>
#include <fstream>
#include <vector>

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

void BST::insert(int value) {
    insert(root, value);
}

void BST::insert(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node(value);
    }
    else if (value < node->data) {
        insert(node->left, value);
    }
    else {
        insert(node->right, value);
    }
}

bool BST::remove(int value) {
    return remove(root, value);
}

bool BST::remove(Node*& node, int value) {
    if (node == nullptr) {
        return false;
    }

    if (value < node->data) {
        return remove(node->left, value);
    }
    else if (value > node->data) {
        return remove(node->right, value);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* temp = node->right;
            while (temp && temp->left) temp = temp->left;
            node->data = temp->data;
            return remove(node->right, temp->data);
        }
    }
    return true;
}

void BST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BST::clear() {
    clear(root);
    root = nullptr;
}

bool BST::findPath(int value, std::vector<int>& path) {
    return findPath(root, value, path);
}

bool BST::findPath(Node* node, int value, std::vector<int>& path) {
    if (node == nullptr) {
        return false;
    }
    path.push_back(node->data);
    if (node->data == value) {
        return true;
    }
    if (value < node->data) {
        return findPath(node->left, value, path);
    }
    return findPath(node->right, value, path);
}

void BST::printPreOrder(Node* node) {
    if (node) {
        std::cout << node->data << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

void BST::printInOrder(Node* node) {
    if (node) {
        printInOrder(node->left);
        std::cout << node->data << " ";
        printInOrder(node->right);
    }
}

void BST::printPostOrder(Node* node) {
    if (node) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        std::cout << node->data << " ";
    }
}

void BST::printTree(int order) {
    if (order == 1) {
        printPreOrder(root);
    }
    else if (order == 2) {
        printInOrder(root);
    }
    else if (order == 3) {
        printPostOrder(root);
    }
    std::cout << std::endl;
}

void BST::saveToFile(Node* node, std::ofstream& outFile) const {
    if (node) {
        outFile.write(reinterpret_cast<const char*>(&node->data), sizeof(node->data));
        saveToFile(node->left, outFile);
        saveToFile(node->right, outFile);
    }
    else {
        int nullMarker = -1; // Используем -1 как маркер конца
        outFile.write(reinterpret_cast<const char*>(&nullMarker), sizeof(nullMarker));
    }
}

void BST::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }
    saveToFile(root, outFile);
}

void BST::loadFromFile(Node*& node, std::ifstream& inFile) {
    int value;
    if (inFile.read(reinterpret_cast<char*>(&value), sizeof(value))) {
        if (value == -1) {
            node = nullptr;
        }
        else {
            node = new Node(value);
            loadFromFile(node->left, inFile);
            loadFromFile(node->right, inFile);
        }
    }
}

void BST::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        throw std::ios_base::failure("Failed to open file for reading");
    }
    clear();
    loadFromFile(root, inFile);
}
    clear(); 
    loadFromFile(root, inFile);
}
