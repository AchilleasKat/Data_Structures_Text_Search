#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include <iostream>
#include <fstream>
#include <string>
#include "NonSortedArray.h"



using namespace std;

//Sorted array data structure. Array is built in NonSortedArray and being inherited.
class SortedArray : public NonSortedArray
{
public:
    SortedArray(string&);
    virtual ~SortedArray();
    void searchArray(string*,int);

protected:

private:
    ofstream results;
    int partition(int,int);
    void quicksort(int,int);
    void swap(string*,string*);
    int binarySearch(string&,int,int,int&);
};

#endif // SORTEDARRAY_H
