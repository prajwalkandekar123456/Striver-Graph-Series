//Problem
/*
You are given a graph with n vertices and m edges.

You can remove one edge from anywhere and add that edge between any two vertices in one operation.

Find the minimum number of operation that will be required to make the graph connected.

If it is not possible to make the graph connected, return -1.

 

Example 1: 

Input:
n=4
m=3
Edge=[ [0, 1] , [0, 2] , [1, 2] ]

Output:
1

Explanation:
Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
 
*/

//Time Complexity :
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
            size[ulp_u]+=size[ulp_v];        }
    }

};
class Solution{
    public:
    int connectingGraph(int n,vector<vector<int>> &edges)
    {
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v))
            {
                cntExtras++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntC = 0;
        for(int i = 0;i<n;i++)
        {
            if(ds.parent[i] == i) cntC++;
        }
        int ans = cntC-1;
        if(cntExtras>=ans) return ans;
        return -1;

    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i = 0;i<m;i++)
    {
        vector<int>  temp;
        for(int j = 0;j<2;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }

    Solution obj;
    int ans = obj.connectingGraph(n,edges);
    cout<<ans<<endl;
    return 0;
}