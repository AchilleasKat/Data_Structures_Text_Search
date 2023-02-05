#include "SortedArray.h"
#include "NonSortedArray.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cmath>
#include <ctime>


using namespace std;

SortedArray::SortedArray(string& mode) :NonSortedArray(mode){
    results.open("results.txt",ios::app);
    clock_t time_req;
    time_req = clock();
    quicksort(0,size-1);
    time_req = clock() - time_req;
    results<<endl;
    results<<"Sorted Array build duration: "<<(float)time_req / CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
    results.close();
}

SortedArray::~SortedArray(){

}

//Function that searches the array to find the data in array searchData.
 void SortedArray::searchArray(string* searchData,int searchSize)
 {
    results.open("results.txt",ios::app);
    clock_t time_req;
    time_req = clock();
    for(int i=0;i<searchSize;i++)
    {
        int quantity=0;
        int index=binarySearch(searchData[i],0,size-1,quantity);
        if(index!=-1)
        {
            results<<"Word: "<<array[index]<<" :"<<quantity<<" times."<<endl;
        }
        else
        {
             results<<"Could not find "<<searchData[i]<<" !"<<endl;
        }
    }
    time_req = clock() - time_req;
    results<<endl;
    results<<"Sorted Array search duration: "<<(float)time_req / CLOCKS_PER_SEC<<" seconds"<<endl<<endl;
    results.close();
}

//Permutation of the Binary Search algorithm function in https://www.geeksforgeeks.org/binary-search/
int SortedArray::binarySearch(string &key,int left,int right,int &quantity)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (array[mid] == key)
            {
                quantity++;
                int i=mid+1;
                while(array[i]==key)
                {
                    quantity++;
                    i++;
                }
                i=mid-1;
                while(array[i]==key)
                {
                    quantity++;
                    i--;
                }
                return mid;
            }

        if (array[mid] > key)
            {
                return binarySearch(key,left, mid - 1,quantity);
            }

        return binarySearch(key,mid + 1, right,quantity);
    }
    return -1;
}


/* The main function that implements QuickSort.
Permutation of the quicksort algorithm function in https://www.geeksforgeeks.org/quick-sort/
*/

void SortedArray::quicksort(int low, int high)
{
    if (low < high)
    {
        int pi = partition( low, high);

        quicksort(low, pi - 1);

        quicksort(pi + 1, high);
    }
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int SortedArray::partition (int low, int high)
{
    string pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void SortedArray::swap(string* a, string* b)
{
    string t = *a;
    *a = *b;
    *b = t;
}
