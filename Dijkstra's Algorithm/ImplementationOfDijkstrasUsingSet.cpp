// Problem
/*Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.

 

Example 1:

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 1 is 9.*/

// Space Complexity : 
// Time Complexity :

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<int> dijkstra(int V,vector<vector<int>> adj[],int S)
{
    set<pair<int,int>> st;
    st.insert({0,S});
    vector<int> dist(V,1e9);
    dist[S] = 0;
    while(!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);
        for(auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWeight = it[1];
            if(dis+edgeWeight < dist[adjNode])
            {
                if(dist[adjNode]!=1e9)
                {
                    st.erase({dist[adjNode],adjNode});

                }
                dist[adjNode] = edgeWeight + dis;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
};
int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj[V];
    for(int i = 0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        vector<int> t1,t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);

    }
    int S;
    cin>> S;
    Solution obj;
    vector<int> ans = obj.dijkstra(V,adj,S);
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}