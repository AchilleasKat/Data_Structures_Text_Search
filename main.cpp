#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cmath>
#include <ctime>
#include "NonSortedArray.h"
#include "SortedArray.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include "Hashtable.h"
#include "List.h"

#define filename "input.txt" // Variable that holds the name of the input file.
#define search_size 1000

using namespace std;

void transformFile(ifstream &, fstream &, int &);
void getRandomWords(fstream &, int &, string *&);
void buildTree(fstream &, ofstream &, BinarySearchTree &);
void createTable(fstream &, ofstream &, Hashtable &);

int main()
{
    srand((unsigned)time(NULL));
    ifstream textFile(filename);
    fstream transformedTextFile;
    transformedTextFile.open("transformed.txt", ios::out);
    ofstream results;
    results.open("results.txt", ios::out);
    results.close();
    int fileLines = 0;
    string *searchData = new string[search_size];

    transformFile(textFile, transformedTextFile, fileLines);
    textFile.close();
    getRandomWords(transformedTextFile, fileLines, searchData);

    string mode = "";
    NonSortedArray *nsArray = new NonSortedArray(mode);
    nsArray->searchArray(searchData, search_size);
    nsArray = NULL;
    delete nsArray;

    mode="sorted";
    SortedArray *sortArray=new SortedArray(mode);
    sortArray->searchArray(searchData, search_size);
    sortArray=NULL;
    delete sortArray;

    BinarySearchTree *bst = new BinarySearchTree();
    buildTree(transformedTextFile, results, *bst);
    bst->findData(searchData, search_size);
    bst = NULL;
    delete bst;


    Hashtable *hashtable = new Hashtable();
    createTable(transformedTextFile, results, *hashtable);
    hashtable->searchHashtable(searchData, search_size);
    hashtable = NULL;
    delete hashtable;

    if (transformedTextFile.is_open())
    {
        transformedTextFile.close();
    }
    if (results.is_open())
    {
        results.close();
    }
    searchData = NULL;
    delete[] searchData;
    return 0;
}

/*Transforms the letters of the input file to lowercase,deletes punctuations and removes excess whitespace*/
void transformFile(ifstream &textFile, fstream &transformedTextFile, int &fileLines)
{
    string word;
    int count = 0;
    int punct = 0; // counter to add a space between words that are split by punctuations (e.g. life-time).

    if (textFile.is_open() && transformedTextFile.is_open())
    {
        while (textFile >> word)
        {
            for (int i = 0, len = word.size(); i < len; i++)
            {
                if (ispunct(word[i]))
                {
                    if (punct == 0)
                    {
                        word.replace(i, 1, " ");
                    }
                    else
                    {
                        word.erase(i--, 1);
                        len = word.size();
                    }
                    punct++;
                }
                else
                {
                    punct = 0;
                    word[i] = tolower(word[i]);
                }
            }
            transformedTextFile << word << " ";
            count++;
            if (count > 20)
            {
                transformedTextFile << endl;
                fileLines++;
                count = 0;
            }
        }
    }
    else
    {
        cout << "Files not open" << endl;
        exit(1);
    }
    transformedTextFile.close();
}

// Getting random word pairs from the transformed file.
void getRandomWords(fstream &transformedTextFile, int &fileLines, string *&searchData)
{
    string word;
    transformedTextFile.open("transformed.txt", ios::in);

    if (transformedTextFile.is_open())
    {
        for (int i = 0; i < search_size; i++)
        {
            int randomNumber = rand() % fileLines;
            int countWords = 0;
            while (!((countWords - 1) == randomNumber))
            {
                transformedTextFile >> word;
                countWords++;
                if (countWords == randomNumber)
                {
                    string temp = word;
                    transformedTextFile >> word;
                    searchData[i] = temp + " " + word;
                }
            }
            transformedTextFile.clear();
            transformedTextFile.seekg(0);
        }
    }
    else
    {
        cout << "file not open" << endl;
        exit(1);
    }
    transformedTextFile.close();
}

// Insertion of nodes to the binary search tree.
void buildTree(fstream &transformedTextFile, ofstream &results, BinarySearchTree &bst)
{
    results.open("results.txt", ios::app);
    clock_t time_req;
    time_req = clock();
    transformedTextFile.open("transformed.txt", ios::in);
    if (transformedTextFile.is_open() && results.is_open())
    {
        string word1, word2;
        while (!transformedTextFile.eof())
        {
            if (word1.empty())
            {
                transformedTextFile >> word1;
            }
            transformedTextFile >> word2;
            string words = word1 + " " + word2;
            Node n(words);
            word1 = word2;
            bst.InsertNode(n);
        }
    }
    else
    {
        cout << "Files not open" << endl;
    }
    time_req = clock() - time_req;
    results << "Binary Tree Build Duration: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl
            << endl;
    transformedTextFile.close();
    results.close();
}

void createTable(fstream &transformedTextFile, ofstream &results, Hashtable &hashtable)
{
    results.open("results.txt", ios::app);
    clock_t time_req;
    time_req = clock();
    transformedTextFile.open("transformed.txt", ios::in);
    if (transformedTextFile.is_open() && results.is_open())
    {
        string word1, word2;
        while (!transformedTextFile.eof())
        {
            if (word1.empty())
            {
                transformedTextFile >> word1;
            }
            transformedTextFile >> word2;
            string words = word1 + " " + word2;
            List item(words);
            word1 = word2;
            hashtable.placeItem(item);
        }
    }
    else
    {
        cout << "Files not open" << endl;
    }
    time_req = clock() - time_req;
    results << "Hash Table Build Duration: " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl
            << endl;
    transformedTextFile.close();
    results.close();
}
