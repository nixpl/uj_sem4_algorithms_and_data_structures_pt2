#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct node
{
    T el; // element
    node<T> *smaller = nullptr;
    node<T> *bigger = nullptr;
};

template <typename T>
class BST
{
protected:
    node<T> *root = nullptr;

    int size = 0;

    bool putInPlace(T element, node<T> *&root);

    bool removeNode(T element, node<T> *&root);

    node<T> *findMin(node<T> *root);

    bool checkPresence(T element, node<T> *&root);

    void inorder(node<T> *root);

    void deleteBST(node<T> *&root);

public:
    ~BST(); // destruktor

    bool add(T element); // zwraca true gdy uda sie dodac nowy element

    bool remove(T element);

    bool isInTree(T element);

    void clear();

    int getSize();

    node<T> *getRoot();

    void printInOrder();
};
