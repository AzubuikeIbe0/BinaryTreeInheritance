#pragma once
#include "TreeNode.h"
class TreeInheritance
{
	friend class TreeNode;
	friend int main();
private:
	TreeNode* root;
	TreeNode* CreateNode(int val);
	TreeNode* DeleteNodePrivate(TreeNode*& node, int value);
	TreeNode* InsertNodePrivate(TreeNode* root, int key);
public:

	void PrintTree(TreeNode* root);
	TreeNode* FindMin(TreeNode* node);
};