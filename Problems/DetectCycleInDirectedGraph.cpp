// Problem
/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle*/

// Time Complexity : O(V+E)
// Space Complexity :O(V)

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
   bool dfs(int node,int vis[],int pathVis[],vector<int> adj[])
   {
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it] && !pathVis[it])
        {
            if(dfs(it,vis,pathVis,adj) == true) return true;
        }
        else if(pathVis[it] == 1) return true;
    }
    pathVis[node] = 0;
    return false;
   }
public:
   bool isCycle(int V,vector<int> adj[])
   {
    int vis[V] = {0};
    int pathVis[V] = {0};
    for(int i = 0;i<V;i++)
    {
        if(!vis[i] && !pathVis[i])
        {
            if(dfs(i,vis,pathVis,adj) == true) return true;
        }
    }
    return false;
   }
};
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i = 0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V,adj);
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}