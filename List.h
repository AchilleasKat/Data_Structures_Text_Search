#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using namespace std;

class List
{
    public:
        List();
        List(string&);
        List(List&);
        ~List();
        void addItem(List*);
        List* getNext() const;
        string getWords() const;
        void setCount() ;
        int getCount() const;

    protected:

    private:
        string words;
        List* next;
        int count;
};

#endif // LIST_H
