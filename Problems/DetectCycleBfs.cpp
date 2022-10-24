// Problem
/*Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.*/

// Time Complexity = O(N+2E)+O(N)
// Space Complexity = O(N)+(N) == O(N)


#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    bool detect(int src,int vis[],vector<int> adj[])
    {
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjacentNode : adj[node])
            {
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode,node});
                }
                else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool isCycle(int V,vector<int> adj[])
    {
        int vis[V] = {0};
        for(int i = 0;i<V;i++)
        {
            if(detect(i,vis,adj)) return true;
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
    if(ans) cout<<"1"<<endl;
    else cout<<"0"<<endl;   
    return 0;
}