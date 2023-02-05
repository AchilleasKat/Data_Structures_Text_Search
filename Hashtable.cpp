#include "Hashtable.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cmath>
#include <ctime>

using namespace std;

Hashtable::Hashtable()
{
    hashtable = new List *[hashtable_size]();
    results.open("results.txt", ios::app);
}

Hashtable::~Hashtable()
{
    for (int i = 0; i < hashtable_size; ++i)
    {
        hashtable[i] = NULL;
        delete hashtable[i];
    }
    results.close();
}

void Hashtable::placeItem(List &item)
{
    string currentData = item.getWords();
    int index = getHash(currentData);
    if (hashtable[index] == NULL)
    {
        hashtable[index] = new List(item);
    }
    else
    {
        int duplicate = 0;
        List *prev = hashtable[index];
        while (prev != NULL)
        {
            string prevData = prev->getWords();
            if (currentData == prevData)
            {
                prev->setCount();
                duplicate++;
                prev = NULL;
                delete prev;
            }
            else if (prev->getNext() != NULL)
            {
                prev = prev->getNext();
            }
            else
            {
                prev->addItem(&item);
                prev = NULL;
                delete prev;
            }
        }
    }
}

void Hashtable::searchHashtable(string *data, int size)
{
    clock_t time_req;
    time_req = clock();
    for (int i = 0; i < size; ++i)
    {
        int index = getHash(data[i]);
        List *prev = hashtable[index];
        while (prev != NULL)
        {
            string prevData = prev->getWords();
            if (data[i] == prevData)
            {
                results << "Word: " << prev->getWords() << " :" << prev->getCount() + 1 << " times." << endl;
                prev = NULL;
                delete prev;
            }
            else if (prev->getNext() != NULL)
            {
                prev = prev->getNext();
            }
            else
            {
                results<<"Could not find "<<data[i]<<" !"<<endl;
                prev = NULL;
                delete prev;
            }
        }
    }
    time_req = clock() - time_req;
    results << endl;
    results << "Hash Table Search Duration: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl
            << endl;
}

// Hash Function for strings from GeeksForGeeks -> https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/
int Hashtable::getHash(const string &s)
{
    const int p = 29791;
    int hash_value;
    int hash_so_far = 0;
    long p_pow = 1;
    string hashedString = s.substr(0, s.find(' '));
    const int n = hashedString.length();
    for (int i = 0; i < n; ++i)
    {
        hash_so_far = (hash_so_far + (hashedString[i] - '0' + 1) * p_pow) % hashtable_size;
        p_pow = (p_pow * p) % hashtable_size;
    }
    hash_value = abs(hash_so_far);
    return hash_value;
}
