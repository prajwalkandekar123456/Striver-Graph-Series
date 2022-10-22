//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Space Complexity = O(N)+O(N)+O(N) == O(N)
// Time Complexity = O(N)+O(2*E)

class Solution {
  private:
    void dfs(int node,vector<int> &ans,vector<int> adj[],int vis[])
    {
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,ans,adj,vis);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        int start = 0;
        vector<int> ans;
        dfs(start,ans,adj,vis);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    
    return 0;
}