#pragma once
#include "BST.h"
#include <iostream>
class setBST
{
	BST<int> bst;

	void inorderSum(setBST &newSet, node<int> *root);
	void inorderCommon(setBST &newSet, node<int> *objectRoot);
	void inorderDifference(setBST &newSet, setBST &object, node<int> *thisRoot);
	bool inorderInclusion(node<int> *objectRoot);

public:
	bool insert(int x);	  // zwraca true gdy sie udalo i false gdy sie nie udalo -> istnieje juz taki element
	bool withdraw(int x); // zwraca true gdy sie udalo i false gdy nie bylo takiego elementu w setcie
	bool isInSet(int i);
	int getSize();
	void clearSet();
	void printSet();
	setBST operator+(setBST &object);
	setBST operator*(setBST &object);
	setBST operator-(setBST &object);
	bool operator==(setBST &object);
	bool operator<=(setBST &object);
};
