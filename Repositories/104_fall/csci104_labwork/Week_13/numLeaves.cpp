#include "numLeaves.h"

int numLeaves(std::shared_ptr<Node> root)
{
	// TODO
	if(root == NULL)
	{
		return 0;
	}
	if(root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return numLeaves(root->left) + numLeaves(root->right);
}