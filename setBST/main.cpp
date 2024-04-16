#include "setBST.h"
#include <iostream>

using namespace std;

int main()
{
    setBST set;
    for (int i = 0; i < 20; i++)
    {
        set.insert(i);
    }

    setBST set2;
    for (int i = 5; i < 22; i++)
    {
        set2.insert(i);
    }

    setBST newSet = set + set2;
    newSet.printSet();
    cout << endl;

    bool test = newSet <= set2;
    cout << test << endl;
    test = set2 <= newSet;
    cout << test << endl;

    setBST smallerSet = newSet - set2;
    smallerSet.printSet();
    cout << endl;

    setBST commonSet = set * set2;
    commonSet.printSet();
    cout << endl;

    // reszta testow--------------------------------------------------

    cout << set.getSize();
    set.printSet();
    cout << endl;

    set.withdraw(10);
    cout << set.getSize();
    set.printSet();
    cout << endl;

    cout << "czy 200 jest w secie: " << set.isInSet(200) << endl;

    cout << "czy 7 jest w secie: " << set.isInSet(7) << endl;

    set.insert(7);

    return 0;
}
