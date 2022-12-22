// Problem
/*
Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-

*/

// Time Complexity : O(V+2E) + O(3N)
// Space Complexity : O(V+2E)
#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
int timer = 0;
    void dfs(int node,int parent,vector<int> &vis,int tin[],int low[],vector<int> &mark,vector<int> adj[])
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,node,vis,tin,low,mark,adj);
                low[node] = min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(child>1 && parent == -1)
        {
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int V,vector<int> adj[])
    {
        vector<int> vis(V,0);
        int tin[V];
        int low[V];
        vector<int> mark(V,0);
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,vis,tin,low,mark,adj);
            }
        }
        vector<int> ans;
        for(int i = 0;i<V;i++)
        {
            if(mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};

int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i = 0;i<V;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    vector<int> ans = obj.articulationPoints(V,adj);
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}