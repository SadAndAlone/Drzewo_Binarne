#pragma once
#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, int value);
    bool remove(Node*& node, int value);
    void clear(Node* node);
    bool findPath(Node* node, int value, std::vector<int>& path);
    void printPreOrder(Node* node);
    void printInOrder(Node* node);
    void printPostOrder(Node* node);
    void saveToFile(Node* node, std::ofstream& outFile) const;
    void loadFromFile(Node*& node, std::ifstream& inFile);

public:
    BST();
    ~BST();

    void insert(int value);
    bool remove(int value);
    void clear();
    bool findPath(int value, std::vector<int>& path);
    void printTree(int order);

    // Новые перегрузки для работы с файлами по имени
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
