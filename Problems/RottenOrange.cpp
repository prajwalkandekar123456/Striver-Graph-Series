// Problem
/**Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.*/

// Space Complexity = O(N*M)
// Time Complexity  = O(N*M)+O(N*M)

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int orangesRotatting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        int cntFresh = 0;
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    cntFresh++;
                }
            }
        }
        int cnt = 0;
        int tm = 0;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && vis[nrow][ncol]!=2)
                {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                }
            }
            
        }
        if(cnt!=cntFresh) return -1;
        return tm;
    }
      
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    Solution obj;
    int ans = obj.orangesRotatting(grid);
    cout<<ans<<endl;
    return 0;
}