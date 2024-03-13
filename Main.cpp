#include <iostream>
#include "TreeInheritance.h"
using namespace std;

int main() {

	TreeInheritance T1;
	TreeNode* root = T1.CreateNode(1);

	root->left = T1.CreateNode(2);
	root->right = T1.CreateNode(3);

	root->left->left = T1.CreateNode(4);
	root->left->right = T1.CreateNode(5);
	root->right->left = T1.CreateNode(6);
	root->right->right = T1.CreateNode(7);

	root->left->left->left = T1.CreateNode(8);
	root->left->left->right = T1.CreateNode(9);
	root->right->left->left = T1.CreateNode(10);
	root->right->left->right = T1.CreateNode(11);

	T1.PrintTree(root);
	cout << endl;

	T1.InsertNodePrivate(root, 7);
	cout << endl;

	T1.PrintTree(root);



	return 0;
}