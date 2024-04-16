#include "PriorityQueue.h"

void PriorityQueue::insert(int x)
{
    if (x == MIN)
    {
        cerr << "number " << MIN << " cannot be inserted" << endl;
        return;
    }

    heap.push_back(x);

    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] > x)
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int PriorityQueue::RemoveRootElem()
{
    if (heap.empty())
    {
        cerr << "queue is empty" << endl;
        return MIN;
    }

    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    int parentIndex = 0;
    int firstChildIndex = 2 * parentIndex + 1;
    int secondChildIndex = firstChildIndex + 1;

    while (true)
    {
        bool first = false;
        bool second = false;

        if (firstChildIndex < (int)heap.size() && heap[parentIndex] > heap[firstChildIndex])
            first = true;

        if (secondChildIndex < (int)heap.size() && heap[parentIndex] > heap[secondChildIndex])
            second = true;

        int direction;
        if (first && second)
            direction = heap[firstChildIndex] < heap[secondChildIndex] ? firstChildIndex : secondChildIndex;
        else if (first)
            direction = firstChildIndex;
        else if (second)
            direction = secondChildIndex;
        else
            break;

        swap(heap[parentIndex], heap[direction]);
        parentIndex = direction;
        firstChildIndex = 2 * parentIndex + 1;
        secondChildIndex = firstChildIndex + 1;
    }

    return root;
}

void PriorityQueue::print()
{
    cout << "[ ";
    for (auto value : heap)
        cout << value << " ";
    cout << "]";
}

int PriorityQueue::getRootElem()
{
    if (heap.empty())
    {
        cerr << " queue is empty " << endl;
        return MIN;
    }
    return heap[0];
}