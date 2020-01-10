/*
https://leetcode.com/problems/number-of-islands/
*/


    int numIslands(vector<vector<char>>& grid) {
      int n = grid.size();
      if(n==0 || grid[0].size() == 0) return 0;
      int m = grid[0].size();

      vector<vector<bool>> visited(n, vector<bool>(m, false));


      vector<int> dirs = {0, 1, 0, -1, 0};
      int numIsland = 0;
      for(int i=0; i<n; ++i)
      {
        for(int j=0; j<m; ++j)
        {
          if(grid[i][j] == '0' || visited[i][j]) continue;
          queue<pair<int,int>> q;
          q.emplace(i, j);
          visited[i][j] = true;
          numIsland++;
          cout<<i<<","<<j<<endl;
          while(!q.empty())
          {
            auto curr = q.front(); q.pop();
           // cout<<curr.first<<" ,"<<curr.second<<endl;
            for(int i = 0; i < dirs.size() - 1; ++i)
            {
              int nr = curr.first + dirs[i];
              int nc = curr.second + dirs[i+1];

              if(!valid(nr, nc, n, m) || visited[nr][nc] || grid[nr][nc] == '0') continue;
              q.emplace(nr, nc);
              visited[nr][nc] = true;
            }
          }
        }
      }

      return numIsland;

    }
private:

    bool valid(int r, int c, int R, int C)
    {
      return r >= 0 && r < R && c >= 0 && c < C;
    }

  };
