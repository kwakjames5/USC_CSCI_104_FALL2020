#include "friend_circles.h"
#include <stack>

using namespace std;

/* Optional: LeetCode #547: "Friend Circles"
 * (https://leetcode.com/problems/friend-circles/)
 * There are N students in a class. Some of them are friends, 
 * while some are not. Their friendship is transitive in nature. 
 * For example, if A is a direct friend of B, and B is a direct friend of C, 
 * then A is an indirect friend of C. We define a friend circle as a 
 * group of students who are direct or indirect friends.
 *
 * You are given a N*N matrix M representing the friend relationship between 
 * students in the class. If M[i][j] = 1, then the ith and jth students are 
 * direct friends with each other, otherwise they are not.
 * 
 * TODO: output the total number of friend circles among all the students. */

int findCircleNum(vector<vector<int>>& M) {
	int count = 0;
	size_t size = M.size();
	vector<bool> visited(size, false);

	for(size_t i = 0; i < size; i++)
	{
		if(!visited[i])
		{
			count++;
			visited[i] = true;
			stack<int> mystack;
			mystack.push(i);
			while(!mystack.empty())
			{
				int temp = mystack.top();
				mystack.pop();
				for(size_t j = 0; j < size; j++)
				{
					if(M[temp][j] == 1 && !visited[j])
					{
						visited[j] = true;
						mystack.push(j);
					}
				}
			}
		}
	}
	return count;
}