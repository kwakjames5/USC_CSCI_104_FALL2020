#include "bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

int rangeSum(Node *root, int L, int R) {
	
	//Base case - called on a null node -> return 0!
	if(root == nullptr)
	{
		return 0;
	}

	int left_sum = rangeSum(root->left, L, R);
	int right_sum = rangeSum(root->right, L, R);
	int sum = left_sum + right_sum;

	if(root->key >= L && root->key <= R)
	{
		sum += root->key;
	}
	
	//Otherwise get the value of the left and right trees under you (recursive call)
	//Sum em
	//Should add node->key to the sum?
	//Return the sum!

	return sum;
}

int getHeight(Node* root)
{
	if(root == nullptr)
	{
		return 0;
	}

	int left_height = getHeight(root->left);
	int right_height = getHeight(root->right);
	return std::max(left_height, right_height) + 1; 
}
    
bool isBalanced(Node *root) {
	if(root == nullptr)
	{
		return true;
	}
	//Get the heights of the left and right subtrees - helper func?
	int left_height = getHeight(root->left);
	int right_height = getHeight(root->right);
	//Determine if this node is balanced! If not ret false!
	if(std::abs(left_height - right_height) > 1)
	{
		return false;
	}
	//Check if there are subtrees under us
	bool left_balanced = isBalanced(root->left);
	bool right_balanced = isBalanced(root->right);
	//Are they balanced?
	if(left_balanced && right_balanced)
	{
		return true;
	}
	//If all nodes are balanced return true!
	return false;
}

/*

Given a binary tree, return the level order traversal of its nodes' values. (i.e. from left to right, level by level).


If you're given this binary tree as input:

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/
vector<vector<int>> levelOrder(Node* root) {
	vector<vector<int>> results;
	if(root == nullptr)
	{
		return results;
	}
	std::queue<Node*> queue;
	queue.push(root);
	while(!queue.empty())
	{
		int size = queue.size();
		std::vector<int> curr_level;

		for(int i = 0; i < size; i++)
		{
			Node* temp = queue.front();
			queue.pop();
			curr_level.push_back(temp->key);

			if(temp->left)
			{
				queue.push(temp->left);
			}

			if(temp->right)
			{
				queue.push(temp->right);
			}
		}
		results.push_back(curr_level);
	}
    return results;
}

