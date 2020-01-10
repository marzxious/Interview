/*
 * Given an undirected graph with n nodes labeled 1..n. Some of the nodes are already connected. The i-th edge connects nodes edges[i][0] and edges[i][1] together. Your task is to augment this set of edges with additional edges to connect all the nodes. Find the minimum cost to add new edges between the nodes such that all the nodes are accessible from each other.
(白話文, 如何用最小的cost把所有的集合union起來)*

Input: n = 6, 
edges = [[1, 4], [4, 5], [2, 3]], 
newEdges = [[1, 2, 5], [1, 3, 10], [1, 6, 2], [5, 6, 5]]

思路 : Union Find with attribute merge

想法: 一但兩個節點connect 起來 它們就屬於同一個group, 因此我們可以用Greedy, 把edge按照cost 排序, 由小到大, 每次挑選不同group之間 最小cost的edge相連. 每次相連計算總cost即可.

*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//sort array by second element ( cost)
bool sortByCost( const vector<int>&  lhs, const vector<int>& rhs) { return ( lhs[2] < rhs[2]); }

class Solution {
public:
	// n : # of nodes, edges : edges between nodes, costs : connection cost between two nodes
	int minCost(int n, vector<vector<int>> edges, vector<vector<int>>  newEdges)
	{
		totalCost = 0; totalFather = n;
		sort(newEdges.begin(), newEdges.end(), sortByCost);

		/*O(N)*/
		for (int i = 1; i <= n; i++)
			father[i] = i;

    /* O(1 * #_of_edge) */
		for (auto edge : edges)
			connect(edge[0], edge[1]); //no cost;

		/* O(1 * #_of_new_edge)*/
		for (auto newEdge : newEdges)
		{
			int x = newEdge[0];
			int y = newEdge[1];

			int cost = newEdge[2];
			if (find(x) == find(y)) continue;
			connect(x, y, cost);  //O(1)
		}

		if(totalFather!=1) return -1; //impossible to connect all group into one group.

		return totalCost;
	}

private:
	unordered_map<int, int> father;  //[模板1] S: O(N)

	int totalCost;
	int totalFather;

	int find(int  x)  //[模板2]  T: O(1) S :O(1)
	{
		if (father[x] == x) return x;
		return father[x] = find(father[x]);
	}

	void connect(int x, int  y, int cost = 0) // [模板 3] T: O(1) S: O(1)
	{
		int father_x = find(x);
		int father_y = find(y);

		if (father_x == father_y) return;

		father[father_x] = father_y
		totalCost += cost;  //連結的cost
		totalFather--;

	}
};


