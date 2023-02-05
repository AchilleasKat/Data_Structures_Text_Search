#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include <string>



using namespace std;

/* Κλάση για την δημιουργία των κόμβων του δέντρου.
Οι pointers left και right αποθηκεύουν τη διεύθυνση
των κόμβων που βρίσκονται αριστερά και δεξία από τον
τρέχων κόμβο και το string words το ζεύγος λέξεων που
διαβάστηκε από το αρχείο.                          */

class Node
{
    public:
        Node();
        Node(const string&);
        Node(Node&);
        virtual ~Node();
        Node* getRightNodePtr()const;
        Node* getLeftNodePtr()const;
        void setRightNode(Node*);
        void setLeftNode(Node*);
        string getWords()const ;
        int getCount()const;
        void setCount();

    protected:

    private:
        Node *right;
        Node *left;
        string words;
        int count;

};

#endif // NODE_H
