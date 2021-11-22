#include "graph.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

bool DFS(Node* start, Node* end) {
	stack<Node*> node_stack;
	node_stack.push(start);

	while(node_stack.empty() == false)
	{
		Node* temp = node_stack.top();
		node_stack.pop();
		if(temp == end)
		{
			return true;
		}
		for(size_t i = 0; i < temp->neighbors.size(); i++)
		{
			if(temp->neighbors[i]->visited == false)
			{
				node_stack.push(temp->neighbors[i]);
				temp->visited = true;
			}
		}
	}
	return false;
}

bool BFS(vector<vector<int> > adjacency_matrix, int start, int end) {
	set<int> checked_set;
	queue<int> node_queue;
	node_queue.push(start);
	checked_set.insert(start);

	while(node_queue.empty() == false)
	{
		int temp = node_queue.front();
		node_queue.pop();
		if(temp == end)
		{
			return true;
		}
		for(size_t i = 0; i < adjacency_matrix[temp].size(); i++)
		{
			if(adjacency_matrix[temp][i] == 1 && (checked_set.find(i) == checked_set.end()))
			{
				node_queue.push(i);
				checked_set.insert(i);
			}
		}
	}
	return false;
}