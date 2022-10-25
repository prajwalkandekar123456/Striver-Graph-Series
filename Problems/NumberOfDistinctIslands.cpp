//Problem
/*Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.*/

// Time Complexity = O(N*M)
//Space Complexity = O(N*M)

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int row,int col, vector<pair<int,int>> &v,vector<vector<int>> &vis,vector<vector<int>> &grid,int row0,int col0)
    {
        int n = grid.size();
        int m  = grid[0].size();
        vis[row][col] = 1;
        v.push_back({row-row0,col-col0});
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        for(int i = 0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow,ncol,v,vis,grid,row0,col0);
            }
        }
    }
public:
    int CountDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>> v;
                    dfs(i,j,v,vis,grid,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    Solution obj;
    int ans = obj.CountDistinctIslands(grid);
    cout<<ans<<endl;
    return 0;
}