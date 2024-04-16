#include "BST.h"

template <typename T>
BST<T>::~BST()
{
    deleteBST(root);
}

template <typename T>
bool BST<T>::add(T element)
{
    if (root == nullptr)
    {
        root = new node<T>;
        root->el = element;
        size++;
        return true;
    }

    bool statement = putInPlace(element, this->root);

    if (statement)
        size++;

    return statement;
}

template <typename T>
bool BST<T>::remove(T element)
{
    bool statement = removeNode(element, this->root);
    if (statement)
        size--;

    return statement;
}

template <typename T>
bool BST<T>::isInTree(T element)
{
    return checkPresence(element, this->root);
}

template <typename T>
void BST<T>::clear()
{
    deleteBST(root);
    size = 0;
}

template <typename T>
int BST<T>::getSize()
{
    return size;
}

template <typename T>
node<T> *BST<T>::getRoot()
{
    return root;
}

template <typename T>
void BST<T>::printInOrder()
{
    cout << "[ ";
    inorder(this->root);
    cout << "]";
}

template <typename T>
bool BST<T>::putInPlace(T element, node<T> *&root)
{
    if (root == nullptr)
    {
        root = new node<T>;
        root->el = element;
        return true;
    }

    if (element < root->el)
        return putInPlace(element, root->smaller);
    else if (element > root->el)
        return putInPlace(element, root->bigger);
    else
        return false;
}

template <typename T>
bool BST<T>::removeNode(T element, node<T> *&root)
{
    if (root == nullptr)
        return false;

    if (element < root->el)
        return removeNode(element, root->smaller);
    else if (element > root->el)
        return removeNode(element, root->bigger);
    else
    {
        if (root->smaller == nullptr && root->bigger == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->smaller == nullptr)
        {
            node<T> *temp = root;
            root = root->bigger;
            delete temp;
        }
        else if (root->bigger == nullptr)
        {
            node<T> *temp = root;
            root = root->smaller;
            delete temp;
        }
        else
        {
            node<T> *temp = findMin(root->bigger);
            root->el = temp->el;
            removeNode(temp->el, root->bigger);
        }
        return true;
    }
}

template <typename T>
node<T> *BST<T>::findMin(node<T> *root)
{
    while (root->smaller != nullptr)
        root = root->smaller;
    return root;
}

template <typename T>
bool BST<T>::checkPresence(T element, node<T> *&root)
{
    if (root == nullptr)
        return false;

    if (element < root->el)
        return checkPresence(element, root->smaller);
    else if (element > root->el)
        return checkPresence(element, root->bigger);
    else
        return true;
}

template <typename T>
void BST<T>::inorder(node<T> *root)
{
    if (root == nullptr)
        return;

    inorder(root->smaller);
    cout << root->el << " ";
    inorder(root->bigger);
}

template <typename T>
void BST<T>::deleteBST(node<T> *&root)
{
    if (root != nullptr)
    {
        deleteBST(root->smaller);
        deleteBST(root->bigger);
        delete root;
        root = nullptr;
    }
}

template class BST<int>;
