//Problem
/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
*/

//Time Complexity:
// Space Complexity :

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st)
    {
        vis[node] = 1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
private:
    void dfs3(int node,vector<int> &vis,vector<int> adjT[])
    {
        vis[node] = 1;
        for(auto it: adjT[node])
        {
            if(!vis[it])
            {
                dfs3(it,vis,adjT);
            }
        }
    }
public:
    int kosarajusAlgo(vector<int>adj[],int V)
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i = 0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,st);
            }
        }

        vector<int> adjT[V];
        for(int i = 0;i<V;i++)
        {
            vis[i] = 0;
            for(auto it: adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
                if(!vis[node])
                {
                    scc++;
                    dfs3(node,vis,adjT);
                }
        }
        return scc;

    }
};
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i = 0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    Solution obj;
    int ans = obj.kosarajusAlgo(adj,V);
    cout<<ans<<endl;
    return 0;
}