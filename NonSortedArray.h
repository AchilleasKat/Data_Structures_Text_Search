#ifndef NONSORTEDARRAY_H
#define NONSORTEDARRAY_H
#include <iostream>
#include <fstream>
#include <string>



using namespace std;

//Non sorted array data structure.
class NonSortedArray
{
public:
  NonSortedArray(string&);
    virtual ~NonSortedArray();
  void BuildArray(ifstream &);
  virtual void searchArray(string*,int);


protected:
  string *array;
  int size;
  void addMemory();

private:
    ifstream file;
    ofstream results;
    string mode;
};

#endif // NONSORTEDARRAY_H
