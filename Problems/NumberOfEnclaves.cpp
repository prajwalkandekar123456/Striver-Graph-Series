//Proble
/*You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.*/

//Space Complexity = O(N*M) 
//Time Complexity  = O(N*M)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
int NumberOfEncaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // int vis[n][m] = {0};
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(i == 0 || j== 0 || i==n-1 || j == m-1){
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
    }
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
        {
           vis[nrow][ncol] = 1;
           q.push({nrow,ncol});
        }
        }
    }
    int count  = 0;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(grid[i][j] == 1 && !vis[i][j])
            {
                count++;
            }
        }
    }
    return count;

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
    int ans = obj.NumberOfEncaves(grid);
    cout<<ans<<endl;
    return 0;
}