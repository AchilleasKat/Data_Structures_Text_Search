#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include <string>



using namespace std;

/* ����� ��� ��� ���������� ��� ������ ��� �������.
�� pointers left ��� right ����������� �� ���������
��� ������ ��� ���������� �������� ��� ����� ��� ���
������ ����� ��� �� string words �� ������ ������ ���
���������� ��� �� ������.                          */

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
