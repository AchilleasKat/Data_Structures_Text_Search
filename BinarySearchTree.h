#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

using namespace std;

/*Binary search tree. Saves the root node address (from the Node class) in the root pointer.
  The root is essential for the insertion of the nodes and the search of the tree.*/

class BinarySearchTree
{
    public:
        BinarySearchTree();
        virtual ~BinarySearchTree();
        virtual void InsertNode(Node &node);
        void findData(string *,int);


    protected:

    private:
        ofstream results;
        Node *root;
};

#endif // BINARYSEARCHTREE_H
