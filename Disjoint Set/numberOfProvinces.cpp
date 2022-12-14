// Problem
/*
    Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
*/

// Time Complexity : O(4 * alpha)
// Space Complexity : O(V * E)


#include <bits/stdc++.h>
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
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i = 0;i<V;i++)
        {
            for(int j = 0;j<V;j++)
            {
                if(adj[i][j] == 1)
                {
                    ds.unionBySize(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<V;i++)
        {
            if(ds.parent[i] == i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};


int main() {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    return 0;
}
