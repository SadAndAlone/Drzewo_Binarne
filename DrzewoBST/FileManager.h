#pragma once
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "BST.h"
#include <string>

class FileManager {
public:
    static void saveTreeToBinaryFile(const BST& tree, const std::string& filename);
    void loadTreeFromBinaryFile(BST& tree, const std::string& filename); 
};

#endif
