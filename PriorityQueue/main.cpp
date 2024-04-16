#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main()
{

    PriorityQueue queue;
    queue.insert(5);
    queue.insert(3);
    queue.insert(4);
    queue.insert(12);
    queue.insert(2);
    cout << "stan kolejki: ";
    queue.print();
    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << "wyciagam element: " << queue.RemoveRootElem() << endl;
        cout << "stan kolejki: ";
        queue.print();
        cout << endl;
    }

    queue.insert(5);
    queue.insert(10);
    queue.insert(16);
    queue.insert(16);
    cout << "stan kolejki: ";
    queue.print();
    cout << endl;

    cout << "wyciagam element: " << queue.RemoveRootElem() << endl;
    cout << "stan kolejki: ";
    queue.print();
    cout << endl;

    queue.insert(60);
    queue.insert(7);
    cout << "stan kolejki: ";
    queue.print();
    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << "wyciagam element: " << queue.RemoveRootElem() << endl;
        cout << "stan kolejki: ";
        queue.print();
        cout << endl;
    }

    return 0;
}