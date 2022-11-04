// Problem
/*You are given a weighted undirected graph having n vertices and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

Example:
Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
1 4 3 5
Explaination:
Shortest path from 1 to n is by the path 1 4 3 5
*/

// Time Complexity : ElogV
// Space Complexity : O(N)


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        vector<int> dist(n+1,1e9),parent(n+1);
        dist[1] = 0;
        for(int i = 1;i<=n;i++) parent[i] = i;
        while(!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            for(auto it: adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(dis+edgeWeight<dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        int node = n;
        vector<int> path;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
        
    }
};
int main() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
}

