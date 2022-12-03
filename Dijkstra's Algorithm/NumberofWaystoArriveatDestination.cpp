//Problem
/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

Example 1:

Input:
n=7, m=10
edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

Output:
4
Explaination:

The four ways to get there in 7 minutes are:
- 0  6
- 0  4  6
- 0  1  2  5  6
- 0  1  3  5  6
*/

//Time Complexity : ElogV
// Space Complexity: N * M

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> dist(n,1e9),ways(n);
        int mod = (1e9 + 7);
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;
                if(dis+edW < dist[adjNode])
                {
                    dist[adjNode] = dis+edW;
                    pq.push({dis+edW,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis+edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        
    }
};

//{ Driver Code Starts.

int main() {
   
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    

    return 0;
}
// } Driver Code Ends