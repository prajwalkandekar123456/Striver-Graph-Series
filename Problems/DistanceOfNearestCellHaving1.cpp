//Problem
/*
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
*/

// Time Complexity = O(N*M)
// Space COmplexity = O(N*M)
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1 && !vis[i][j]){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            for(int i = 0;i<4;i++)
            {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dist;
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
    vector<vector<int>> ans = obj.nearest(grid);
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";

        }
        cout<<endl;
    }
    return 0;
}