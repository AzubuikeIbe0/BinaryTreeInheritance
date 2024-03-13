#pragma once
#include "TreeInheritance.h"

class TreeNode
{
	friend class TreeInheritance;
	friend int main();
private:
	int data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode();
};