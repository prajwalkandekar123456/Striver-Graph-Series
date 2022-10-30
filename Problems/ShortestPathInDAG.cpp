// Problem
/*Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i, 0<=i

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

 

Example:

Input:
n = 6, m= 7
edge=[[0,1,2],[0,4,1],[4,5,4]
,[4,2,2],[1,2,3],[2,3,6],[5,3,1]]

Output:
0 2 3 6 1 5*/

// Space Complexity : 
// Time Complexity :

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
     void topoSort(int node,vector<pair<int,int>> adj[],int vis[],stack<int> &st)
     {
         vis[node] =1;
         for(auto it : adj[node])
         {
             int v = it.first;
             if(!vis[v]){
                 topoSort(v,adj,vis,st);
             }
         }
         st.push(node);
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i = 0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        int vis[N] = {0};
        stack<int> st;
        for(int i = 0;i<N;i++)
        {
            if(!vis[i])
            {
                topoSort(i,adj,vis,st);
            }
        }
        // Step 2
        vector<int> dist(N);
        for(int i = 0;i<N;i++){
          dist[i] = 1e9;  
        } 
        dist[0] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            for(auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if(dist[node]+ wt < dist[v])
                {
                    dist[v] = dist[node]+wt;
                }
            }
            
        }
        for(int i = 0;i<N;i++)
            {
                if(dist[i] == 1e9) dist[i] = -1;
            }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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
