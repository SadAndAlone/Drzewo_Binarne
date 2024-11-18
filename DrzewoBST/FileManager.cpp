#include "FileManager.h"
#include <fstream>

void FileManager::saveTreeToBinaryFile(const BST& tree, const std::string& filename) {
    tree.saveToFile(filename);
}

void FileManager::loadTreeFromBinaryFile(BST& tree, const std::string& filename) {
    tree.loadFromFile(filename);
}
