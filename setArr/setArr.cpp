#include "setArr.h"
#include <string>

setArr::setArr()
{
    table = new bool[universeSize]{false};
    size = 0;
}

void setArr::insert(int x)
{
    if (checkRangeCorrectness(x))
    {
        if (!isInSet(x))
        {
            table[x] = true;
            size++;
        }
        else
            std::cerr << "there is already such element in this set" << std::endl;
    }
    else
        std::cerr << "number out of range" << std::endl;
}

void setArr::withdraw(int x)
{
    if (checkRangeCorrectness(x))
    {
        table[x] = false;
        size--;
    }
    else
        std::cerr << "number out of range" << std::endl;
}

bool setArr::isInSet(int i)
{
    if (checkRangeCorrectness(i) && table[i])
        return true;
    else
        return false;
}

int setArr::getSize()
{
    return size;
}

void setArr::clearSet()
{
    delete[] table;
    table = new bool[universeSize]{false};
    size = 0;
}

void setArr::printSet()
{
    int counter = 0;
    std::cout << "[";
    for (int i = 0; i < universeSize; i++)
    {
        if (table[i])
        {
            std::cout << i;
            if (counter == size - 1)
                break;
            std::cout << ", ";
            counter++;
        }
    }
    std::cout << "]";
}

setArr setArr::operator+(setArr &object)
{
    setArr newSet;
    int limit = this->size + object.getSize();
    int counter = 0;
    for (int i = 0; i < universeSize && counter < limit; i++)
    {
        if (this->table[i] || object.isInSet(i))
        {
            newSet.insert(i);
            counter++;
        }
    }
    return newSet;
}

setArr setArr::operator*(setArr &object)
{
    setArr newSet;
    int limit = this->size < object.getSize() ? this->size : object.getSize();
    int counter = 0;
    for (int i = 0; i < universeSize && counter < limit; i++)
    {
        if (this->table[i] && object.isInSet(i))
        {
            newSet.insert(i);
            counter++;
        }
    }
    return newSet;
}

setArr setArr::operator-(setArr &object)
{
    setArr newSet;
    int limit = this->size;
    int counter = 0;
    for (int i = 0; i < universeSize && counter < limit; i++)
    {
        if (this->table[i] && !object.isInSet(i))
        {
            newSet.insert(i);
            counter++;
        }
    }
    return newSet;
}

bool setArr::operator==(setArr &object)
{
    if (this->size != object.getSize())
        return false;

    return *this <= object;
}

bool setArr::operator<=(setArr &object)
{
    int limit = object.getSize();
    int counter = 0;
    for (int i = 0; i < universeSize && counter < limit; i++)
    {
        // if (!this->table[i] && object.isInSet(i))
        //     return false;
        if (object.isInSet(i))
        {
            counter++;

            if (!this->table[i])
                return false;
        }
    }
    return true;
}

bool setArr::checkRangeCorrectness(int x)
{
    if (x >= 0 && x < universeSize)
        return true;
    else
        return false;
}
