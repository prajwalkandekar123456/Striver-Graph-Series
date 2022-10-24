// Time Complexity = O(N)
// Space Complexity = O(N+2E)

#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    bool dfs(int node,int parent,int vis[],vector<int> adj[])
    {
        vis[node] = 1;
        for(auto adjacentNode : adj[node])
        {
            if(!vis[adjacentNode])
            {
                if(dfs(adjacentNode,node,vis,adj) == true) return true ;
            }
            else if(parent!=adjacentNode){
                return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V,vector<int> adj[])
    {
        int vis[V] = {0};
        // For Multiple components
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,vis,adj)==true) return true;
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