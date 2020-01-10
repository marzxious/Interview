/*
Given a 2D grid, each cell is either a zombie 1 or a human 0. Zombies can turn adjacent (up/down/left/right) human beings into zombies every hour. Find out how many hours does it take to infect all humans ?
https://leetcode.com/discuss/interview-question/411357/
related : https://leetcode.com/problems/rotting-oranges/

思路 : 典型的multisource BFS, 把所有zombie放入queue, 然後一次pop 出同一層的zombie,　把它們的鄰居標記成zombie, repeat.

*/


#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
	int minHours(vector<vector<int>> grid)
	{
		int n = grid.size();
		if (n == 0 ||  grid[0].size() == 0) return 0;
		int m = grid[0].size();

		int hourSpent = 0;
		int people = 0;

		queue<pair<int,int>>  zombies;

		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == 0) {
					people++;
					continue;
				}
				zombies.emplace(i, j);
			}
		}

		int  sz;
		vector<int> dirs = { 0, 1, 0, -1, 0 };
		while(!zombies.empty())
		{
			hourSpent++;
			for (int sz = zombies.size(); sz > 0; sz--)
			{
				auto zombie = zombies.front(); zombies.pop();
				for (int j = 0; j < dirs.size() - 1; ++j)
				{
					int nr = zombie.first + dirs[j];
					int nc = zombie.second + dirs[j + 1];
					if (!InRangeAndIsHuman(nr, nc, grid)) continue;
					grid[nr][nc] = 1;
					people--;
					zombies.emplace(nr, nc);
				}
			}

			if (people == 0) //坑
				break;
		}

		return hourSpent;
	}

	bool InRangeAndIsHuman( int r, int c, vector<vector<int>>& grid )
	{
		return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] !=1;
	}
};
