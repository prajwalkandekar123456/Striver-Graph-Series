// Problem
/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
*/

// Time Complexity : O(V+2E)
// Space Complexity : O(V+2E)+O(3N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
int timer = 1;
    void dfs(int node,int parent,vector<int> &vis,vector<int> adj[],int low[],int tin[],vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        for(auto it : adj[node])
        {
            if(it == parent) continue;
            if(vis[it] == 0)
            {
                dfs(it,node,vis,adj,low,tin,bridges);
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node])
                {
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n,vector<vector<int>> &connections)
    {
        vector<int>adj[n];
        for(auto it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int low[n],tin[n];
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,low,tin,bridges);
        return bridges;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> connections;
    for(int i = 0;i<n;i++)
    {
        vector<int> temp;
        for(int j = 0;j<2;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        connections.push_back(temp);
    }
    Solution obj;
    vector<vector<int>> ans = obj.criticalConnections(n,connections);
    for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j<2;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}