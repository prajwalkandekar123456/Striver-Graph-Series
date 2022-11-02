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

// Time Complexity :
// Space Complexity :

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dijkstra(int V,vector<vector<int>> adj[],int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,1e9);
        pq.push({0,S});
        dist[S] = 0;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node])
            {
                int edgeWeight = it[1];
                int adjNode = it[0];
                if(dis+edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
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
        vector<int> v1,v2;
        v1.push_back(v);
        v1.push_back(w);
        adj[u].push_back(v1);
        v2.push_back(u);
        v2.push_back(w);
        adj[v].push_back(v2);
    }
    int S;
    cin>>S;
    Solution obj;
    vector<int> ans = obj.dijkstra(V,adj,S);
    for(auto it : ans)
    {
        cout<< it <<" ";
    }
    cout<<endl;
    return 0;
}