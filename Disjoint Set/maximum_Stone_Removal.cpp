// Problem
/*

There are n stones at some integer coordinate points on a 2D plane. Each coordinate point may have at most one stone.

You need to remove some stones. 

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the maximum possible number of stones that you can remove.

 

Example 1:

Input:
n=6
[[0 0] ,[ 0 1], [1 0] ,[1 2] ,[2 1] ,[2 2]]

Output:
5

Example:
One way to remove 5 stones are
1--[0,0]
2--[1,0]
3--[0,1]
4--[2,1]
5--[1,2]
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
public:
    int maximumStoneRemoval(vector<vector<int>> &stones,int n)
    {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones)
        {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int> stoneNodes;

        for(auto it: stones)
        {
            int nodeRow = it[0];
            int nodeCol  = it[1];
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int count = 0;
        for(auto it : stoneNodes)
        {
            if(ds.findUPar(it.first) == it.first) count++;
        }
        return n-count;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> stones;
    for(int i = 0;i<n;i++)
    {
        vector<int> temp;
       
        for(int j = 0;j<2;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        stones.push_back(temp);
    }

    Solution obj;
    int ans = obj.maximumStoneRemoval(stones,n);
    cout<<ans<<endl; 
    return 0;
}