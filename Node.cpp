#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

Node::Node()
{
    right=NULL;
    left=NULL;
    words="";
    count=0;
}

Node::Node(const string &w)
{
    right=NULL;
    left=NULL;
    words=w;
    count=0;
}

Node::Node(Node &n)
{
    right=n.getRightNodePtr();
    left=n.getLeftNodePtr();
    words=n.getWords();
    count=0;
}

Node::~Node()
{
    right=NULL;
    left=NULL;
    delete right;
    delete left;
}

Node* Node::getRightNodePtr()const
{return right;}
Node* Node::getLeftNodePtr()const
{return left;}
void Node::setRightNode(Node *n)
{
    right=new Node(*n);
}
void Node::setLeftNode(Node *n)
{
    left=new Node(*n);
}
string Node::getWords()const
{return words;}
int Node::getCount()const
{return count;}
void Node::setCount()
{count++;}
