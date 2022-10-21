#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        for(int j = 0;j<adj[u].size;i++)
        {
            cout<<adj[i][j]<<" ";
        }
    }
    
    
    return 0;
}