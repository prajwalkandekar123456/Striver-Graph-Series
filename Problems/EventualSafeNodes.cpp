// Problem
/*A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.*/

// Space complexity : O(N+E)
// Time Complexity : O(N+E)

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool dfs(int node,vector<int> adj[],int vis[],int pathVis[],int check[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pathVis,check)==true){
                    check[it]  = 0;
                    return true;
                }
            }
            else if(pathVis[it])
            {
                check[it] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> isSafeNodes(int V,vector<int> adj[])
    {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,pathVis,check);
            }
        }
        for(int i = 0;i<V;i++)
        {
            if(check[i] == 1)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
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
        // adj[v].push_back(u);
    }
    Solution obj;
    vector<int> ans = obj.isSafeNodes(V,adj);
    for(int i = 0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}