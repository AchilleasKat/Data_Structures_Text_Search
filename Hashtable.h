#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "List.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cmath>
#include <ctime>

#define hashtable_size 1009 //prime number in order to achieve optimal hashing
//#define hashtable_size 10007

using namespace std;

//Hash Table data structure.
class Hashtable
{
    public:
        Hashtable();
        ~Hashtable();
        void searchHashtable(string*,int);
        void placeItem(List&);

    protected:

    private:
        ifstream file;
        ofstream results;
        List **hashtable;
        int getHash(const string&);
};

#endif // HASHTABLE_H
