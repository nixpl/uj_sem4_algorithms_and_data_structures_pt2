#pragma once
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class PriorityQueue
{
protected:
    const int MIN = numeric_limits<int>::min(); // a value that cannot be placed in the queue and is used to return as information about the failure of a given method
    vector<int> heap;

public:
    void insert(int x);   // does not accept the MIN value
    int RemoveRootElem(); // returns the MIN value when the heap is empty
    void print();         // optionally display subsequent elements of the matrix in which the heap is stored.
    int getRootElem();    // returns the MIN value when the heap is empty
};