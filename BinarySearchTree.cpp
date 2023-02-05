#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include "Node.h"

using namespace std;


BinarySearchTree::BinarySearchTree()
{
    root=NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    root=NULL;
    delete root;
}

void BinarySearchTree::InsertNode(Node &node)
{
     string currentNodeData=node.getWords();
    if(root == NULL)
    {
        root=new Node(node);
    }
    else
    {
        Node *prev = root;
        while(prev!=NULL)
        {
            string prevNodeData=prev->getWords();
            if( prevNodeData == currentNodeData )
            {
                prev->setCount();
                prev=NULL;
            }else if( prevNodeData < currentNodeData )
            {
                if(prev->getRightNodePtr()!=NULL)
                {
                    prev=prev->getRightNodePtr();
                }else
                {
                    prev->setRightNode(&node);
                    prev=NULL;
                    delete prev;
                }
            }else
            {
                if( prev->getLeftNodePtr()!= NULL )
                {
                    prev=prev->getLeftNodePtr();

                }else
                {
                    prev->setLeftNode(&node);
                    prev=NULL;
                    delete prev;
                }
            }
        }
    }
}

//Function that implements the search on the tree.
void BinarySearchTree::findData(string *searchData,int size)
{
    results.open("results.txt",ios::app);
    clock_t time_req;
    time_req = clock();
    for(int i=0;i<size;i++)
    {
        Node *prev=root;

        while(prev!=NULL)
        {
            string prevNodeData=prev->getWords();
            if( prevNodeData == searchData[i] )
            {
                int quantity=prev->getCount()+1;
                results<<"Word: "<<searchData[i]<<" :"<<quantity<<" times."<<endl;
                prev=NULL;
            }else if( prevNodeData < searchData[i] )
            {
                if(prev->getRightNodePtr()!=NULL)
                {
                    prev=prev->getRightNodePtr();
                }else
                {
                    prev=NULL;
                    results<<"Could not find "<<searchData[i]<<" !"<<endl;
                }
            }else if( prevNodeData > searchData[i] )
            {
                if( prev->getLeftNodePtr()!= NULL )
                {
                    prev=prev->getLeftNodePtr();

                }else
                {
                    prev=NULL;
                    results<<"Could not find "<<searchData[i]<<" !"<<endl;
                }
            }
    }
    }
    time_req = clock() - time_req;
    results<<endl;
    results<<"Binary Tree Search Duration: "<<(float)time_req / CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
    results.close();
}

