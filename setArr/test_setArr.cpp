#include "setArr.h"
#include <iostream>

using namespace std;

int main()
{
    setArr set;
    for (int i = 0; i < 20; i++)
    {
        set.insert(i);
    }

    setArr set2;
    for (int i = 5; i < 22; i++)
    {
        set2.insert(i);
    }

    setArr newSet = set + set2;
    cout << "newSet = set + set2 = ";
    newSet.printSet();
    cout << endl;

    bool test = newSet <= set2;
    cout << "newSet <= set2: " << test << endl;
    test = set2 <= newSet;
    cout << "set2 <= newSet: " << test << endl;

    setArr smallerSet = newSet - set2;
    cout << "smallerSet = newSet - set2 =";
    smallerSet.printSet();
    cout << endl;

    setArr commonSet = set * set2;
    cout << "commonSet = set * set2 =";
    commonSet.printSet();
    cout << endl;

    // reszta testow--------------------------------------------------

    cout << "size: " << set.getSize() << " set =";
    set.printSet();
    cout << endl;

    set.withdraw(10);
    cout << "size: " << set.getSize() << " set =";
    set.printSet();
    cout << endl;

    cout << "czy 200 jest w secie: " << set.isInSet(200) << endl;
    set.withdraw(200);

    cout << "set.insert(7): ";
    set.insert(7);

    return 0;
}