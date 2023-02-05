#include "List.h"
#include <iostream>
#include <string>

using namespace std;

List::List()
{
    next=NULL;
    count=0;
}

List::List(string &w)
{
    next=NULL;
    words=w;
    count=0;
}

List::List(List &l)
{
    next=l.getNext();
    words=l.getWords();
    count=0;
}


List::~List()
{
    next=NULL;
    delete next;
}

void List::addItem(List *item)
{
    next=new List(*item);
}


List* List::getNext() const {return next;}
string List::getWords() const {return words;}
void List::setCount(){count++;}
int List::getCount() const {return count;}
