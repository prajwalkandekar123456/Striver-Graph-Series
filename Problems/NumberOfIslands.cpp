#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
   void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis)
   {
      vis[row][col] = 1;
      int n = grid.size();
      int m = grid[0].size();
      queue<pair<int,int>> q;
      q.push({row,col});
      while(!q.empty())
      {
        int rows = q.front().first;
        int cols = q.front().second;
        q.pop();
        for(int delrow = -1;delrow<=1;delrow++)
        {
            for(int delcol = -1;delcol<=1;delcol++)
            {
                int nrow = rows+delrow;
                int ncol = cols+delcol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1'&&!vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
      }
   }
public:
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int row = 0;row<n;row++)
    {
        for(int col = 0;col<m;col++)
        {
             if(grid[row][col] == '1' && !vis[col][row]){
                bfs(row,col,grid,vis);
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
    vector<vector<char>> grid(n,vector<char> (m,'#'));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    Solution obj;
    int ans = obj.numIslands(grid);
    cout<<ans<<endl;
    return 0;
}