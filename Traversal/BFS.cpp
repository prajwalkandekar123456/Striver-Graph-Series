#include<bits/stdc++.h>
using namespace std;
// This is for Directed graph
// Time Complexity = O(N) + O(2E)
// Space Complexity = O(3N) == O(N)
class Solution{
    public :

    vector<int> BfsOfGraph(int V,vector<int> adj[])
    {
        //visited array
        int vis[V] = {0};
        //starting travesring from level 0
        vis[0] = 1;
        //storing each node
        queue<int> q;
        q.push(0);
        // An array storing bfs
        vector<int> bfs;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            // Adjacent elements of node
            for(auto it : adj[node])
            {
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
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
    vector<int> ans = obj.BfsOfGraph(V,adj);
    for(int i = 0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}