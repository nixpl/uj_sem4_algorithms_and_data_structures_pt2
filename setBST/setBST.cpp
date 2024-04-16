#include "setBST.h"
#include <string>

bool setBST::insert(int x)
{
    if (!bst.add(x))
        return false;
    return true;
}

bool setBST::withdraw(int x)
{
    if (!bst.remove(x))
        return false;
    return true;
}

bool setBST::isInSet(int i)
{
    return bst.isInTree(i);
}

int setBST::getSize()
{
    return bst.getSize();
}

void setBST::clearSet()
{
    bst.clear();
}

void setBST::printSet()
{
    bst.printInOrder();
}

void setBST::inorderSum(setBST &newSet, node<int> *root)
{
    if (root == nullptr)
        return;

    inorderSum(newSet, root->smaller);
    newSet.insert(root->el);
    inorderSum(newSet, root->bigger);
}

setBST setBST::operator+(setBST &object)
{
    setBST newSet;
    inorderSum(newSet, this->bst.getRoot());
    inorderSum(newSet, object.bst.getRoot());
    return newSet;
}

void setBST::inorderCommon(setBST &newSet, node<int> *objectRoot)
{
    if (objectRoot == nullptr)
        return;

    inorderCommon(newSet, objectRoot->smaller);

    if (isInSet(objectRoot->el))
        newSet.insert(objectRoot->el);

    inorderCommon(newSet, objectRoot->bigger);
}

setBST setBST::operator*(setBST &object)
{
    setBST newSet;
    inorderCommon(newSet, object.bst.getRoot());
    return newSet;
}

void setBST::inorderDifference(setBST &newSet, setBST &object, node<int> *thisRoot)
{
    if (thisRoot == nullptr)
        return;

    inorderDifference(newSet, object, thisRoot->smaller);

    if (!object.isInSet(thisRoot->el))
        newSet.insert(thisRoot->el);

    inorderDifference(newSet, object, thisRoot->bigger);
}

setBST setBST::operator-(setBST &object)
{
    setBST newSet;
    inorderDifference(newSet, object, this->bst.getRoot());
    return newSet;
}

bool setBST::operator==(setBST &object)
{
    if (bst.getSize() != object.getSize())
        return false;

    return *this <= object;
}

bool setBST::inorderInclusion(node<int> *objectRoot)
{
    if (objectRoot == nullptr)
        return true;

    bool statement = inorderInclusion(objectRoot->smaller);

    if (!isInSet(objectRoot->el))
        statement = false;

    if (statement)
        statement = inorderInclusion(objectRoot->bigger);

    return statement;
}

bool setBST::operator<=(setBST &object)
{
    return inorderInclusion(object.bst.getRoot());
}
