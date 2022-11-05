// Problem
/*Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.

Example 1:

Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.*/

// Time COmplexity : 
// Space Complexity :

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
int shortestPath(vector<vector<int>> &grid,pair<int,int> source,pair<int,int> destination)
{
    int n = grid.size();
    int m = grid[0].size();
    if(source.first == destination.first && source.second == destination.second) return 0;
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    queue<pair<int,pair<int,int>>> q;
    dist[source.first][source.second] = 0;
    q.push({0,{source.first,source.second}});
    int delrow[] = {-1,0,+1,0};
    int delcol[] = {0,+1,0,-1};
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        for(int i = 0;i<4;i++)
        {
            int newr = r+delrow[i];
            int newc = c+delcol[i];
            while(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc] == 1 && dis+1<dist[newr][newc])
            {
               dist[newr][newc] = dis+1;
               if(destination.first == newr && destination.second == newc) return dis+1;
               q.push({dis+1,{newr,newc}});
            }
        }
    }
    return -1;
}
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int> (m,0));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    } 
    pair<int,int> source,destination;
    cin>>source.first>>source.second;
    cin>>destination.first>>destination.second;
    Solution obj;
    int ans = obj.shortestPath(grid,source,destination);
    cout<<ans<<endl;
    return 0;
}