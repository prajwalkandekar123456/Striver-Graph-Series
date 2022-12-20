//Problem

/*
You are given an n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.

You can change at most one cell in grid from 0 to 1.

You need to find the largest group of connected  1's.

Two cells are said to be connected if both are adjacent to each other and both have same value.

Example 1

Input:
2
1 1
0 1

Output:
4

Explanation:
By changing cell (2,1) ,we can obtain a connected group of 4 1's
1 1
1 1
*/

// Time Complexity :
// Space Complexity :

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<=n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution{
private:
    bool isValid(int newr,int newc,int n)
    {
        return newr>=0 && newr<n && newc>=0 && newc<n;
    }
public:
    int maximumConnectedGraph(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int row = 0;row<n;row++)
        {
            for(int col = 0;col<n;col++)
            {
                if(grid[row][col] == 0) continue;
                int dr[] = {-1,0,+1,0};
                int dc[] = {0,-1,0,+1};
                for(int i = 0;i<4;i++)
                {
                    int newr = dr[i] + row;
                    int newc = dc[i]+col;
                    if(isValid(newr,newc,n) && grid[newr][newc] == 1)
                    {
                        int nodeNo = row*n + col;
                        int adjNodeNo = newr*n+newc;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        int mx = 0;
        for(int row = 0;row<n;row++)
        {
            for(int col = 0;col<n;col++)
            {
                if(grid[row][col] == 1) continue;
                int dr[] = {-1,0,+1,0};
                int dc[] = {0,-1,0,+1};
                set<int>components;
                for(int i = 0;i<4;i++)
                {
                    int newr = dr[i]+row;
                    int newc = dc[i]+col;
                    if(isValid(newr,newc,n))
                    {
                        if(grid[newr][newc] == 1)
                        {
                            components.insert(ds.findUPar(newr*n + row));
                        }
                    }
                }
                int sizeTotal = 0;
                for(auto it : components)
                {
                    sizeTotal+=ds.size[it];
                }
                mx = max(mx,sizeTotal+1);
            }
        }
        for(int cellNo = 0;cellNo<n;cellNo++)
        {
            mx = max(mx,ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n,0));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }

    Solution obj;
    int ans = obj.maximumConnectedGraph(grid);
    cout<<ans<<endl;
    return 0;
}