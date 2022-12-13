//problem
/*
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

 

Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
*/

// Time Complexity : O(E(log(E))
// Space Complexity : O(E+V)

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> size,parent;
    public:

    DisjointSet(int n)
    {
        size.resize(n+1);
        parent.resize(n+1);
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
    int spanningTree(int V,vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mWt = 0;
        for(auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUPar(u)!= ds.findUPar(v))
            {
                mWt+=wt;
                ds.unionBySize(u,v);
            }
        }
        return mWt;

    }

};
int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj[V];
    int i = 0;
    while(i++<E)
    {
        int u,v,w;
        cin>>u>>v>>w;
        vector<int> v1,v2;
        v1.push_back(v);
        v1.push_back(w);
        adj[u].push_back(v1);
        v2.push_back(u);
        v2.push_back(w);
        adj[v].push_back(v2);
    }
    Solution obj;
    int ans = obj.spanningTree(V,adj);
    cout<<ans<<endl;  
    return 0;
}