#include "setList.h"
#include <string>
#include <algorithm>

void setList::insert(int x)
{
    if (!isInSet(x))
        vec.push_back(x);
    else
        std::cerr << "there is already such element in this set" << std::endl;
}

void setList::withdraw(int x)
{
    auto iterator = std::find(vec.begin(), vec.end(), x);
    if (iterator != vec.end())
        vec.erase(iterator);
}

bool setList::isInSet(int i)
{
    auto iterator = std::find(vec.begin(), vec.end(), i);
    if (iterator != vec.end())
        return true;
    else
        return false;
}

int setList::getSize()
{
    return vec.size();
}

void setList::printSet()
{
    int i;
    int size = vec.size();
    std::cout << "[";
    for (i = 0; i < size - 1; i++)
    {
        std::cout << vec.at(i);
        std::cout << ", ";
    }
    std::cout << vec.at(i) << "]";
}

setList setList::operator+(setList &object)
{
    setList newSet;
    newSet.vec = std::vector<int>(vec.begin(), vec.end()); // gleboka kopia vektora

    for (auto that_element : object.vec)
    {
        if (!isInSet(that_element))
            newSet.insert(that_element);
    }
    return newSet;
}

setList setList::operator*(setList &object)
{
    setList newSet;
    newSet.vec = std::vector<int>(vec.begin(), vec.end()); // gleboka kopia vektora

    for (auto this_element : vec)
    {
        if (!object.isInSet(this_element))
            newSet.withdraw(this_element);
    }
    return newSet;
}

setList setList::operator-(setList &object)
{
    setList newSet;
    newSet.vec = std::vector<int>(vec.begin(), vec.end()); // gleboka kopia vektora

    for (auto that_element : object.vec)
    {
        newSet.withdraw(that_element);
    }
    return newSet;
}

bool setList::operator==(setList &object)
{
    if ((int)vec.size() != object.getSize())
        return false;

    return *this <= object;
}

bool setList::operator<=(setList &object)
{
    for (auto that_element : object.vec)
    {
        if (!isInSet(that_element))
            return false;
    }
    return true;

    // for (auto this_element : vec)
    // {
    //     if (!object.isInSet(this_element))
    //         return false;
    // }
    // return true;
}