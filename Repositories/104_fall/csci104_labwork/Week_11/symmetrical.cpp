#include "symmetrical.h"

bool isSymmetrical(Node *root)
{
	// TODO
	if(root == nullptr)
	{
		return true;
	}
	isSymmetricalHelper(root->left, root->right);
}

bool isSymmetricalHelper(Node* left, Node* right)
{
	// Base case
	if(left == nullptr || right == nullptr)
	{
		return (left == nullptr && right == nullptr);
	}

	return (left->key == right->key) 
	&& isSymmetricalHelper(left->left, right->right) // outer check
	&& isSymmetricalHelper(left->right, right->left); // inner check
}