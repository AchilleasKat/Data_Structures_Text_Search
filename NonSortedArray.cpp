#include "NonSortedArray.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>



using namespace std;

NonSortedArray::NonSortedArray(string& m){
  mode=m;
  size=10000;
  array=new string[size];
  file.open("transformed.txt");
  BuildArray(file);
}

NonSortedArray::~NonSortedArray(){

  if(file.is_open())
    {
        file.close();
    }
     if(results.is_open())
    {
        results.close();
    }
  array=NULL;
  delete[]array;
}

void NonSortedArray::BuildArray(ifstream &file)
{
    results.open("results.txt",ios::app);
    clock_t time_req;
    time_req = clock();
    string word1,word2;
    word1=word2="";
    int i=0;
    while(!file.eof())
    {
            if(word1.empty())
            {
                    file>>word1;
            }
            file>>word2;
            if(i==size)
                {
                    addMemory();
            }else
            {
                string words;
                words=word1+" "+word2;
                array[i]=words;
                word1=word2;
            }
            i++;
        }
        size=i;//Disregard the empty spaces of the array.
        if(mode.empty())
        {
            time_req = clock() - time_req;
            results<<"Non Sorted Array build duration: "<<(float)time_req / CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
        }
        results.close();
}

void NonSortedArray::addMemory(){
    string *newArray=new string[size*2];
    for(int i=0;i<size;i++) {
      newArray[i]=array[i];
    }
  size=size+size/2;
  array=NULL;
  delete[]array;
  array=newArray;
  newArray=NULL;
  delete newArray;
}

void NonSortedArray::searchArray(string* searchData,int searchSize)
{
    results.open("results.txt",ios::app);
    clock_t time_req;
    time_req = clock();
    for(int i=0;i<searchSize;i++)
    {
        int quantity=0;
        for(int j=0;j<size;j++)
        {
            if(searchData[i]==array[j]){
            quantity++;
        }
        if(j==size-1)
        {
            if(quantity>0)
            {
                results<<"Word: "<<searchData[i]<<" :"<<quantity<<" times."<<endl;
            }else
            {
                 results<<"Could not find "<<searchData[i]<<" !"<<endl;
            }
        }
        }
    }
    time_req = clock() - time_req;
    results<<endl;
    results<<"Non Sorted Array search duration: "<<(float)time_req / CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
    results.close();
}

