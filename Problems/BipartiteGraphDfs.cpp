// Problem
/*Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.*/

// Time Complexity : O(V+2E)
// Space Complexity : O(V)

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
   bool check(int node,int col,int color[],vector<int> adj[])
   {
       color[node] = col;
       for(auto it: adj[node])
       {
         if(color[it] == -1)
         {
            if(check(it,!col,color,adj) == false) return false;
         }
         else if(color[it] == color[node])
         {
            return false;
         }
       }
       return true;
   }
      
   
public:
   bool isBipartite(int V,vector<int> adj[])
   {
     int color[V];
     for(int i = 0;i<V;i++)
     {
        color[i] = -1;

     }
     for(int i = 0;i<V;i++)
     {
        if(color[i] == -1)
        {
            if(check(i,0,color,adj) == false){
                return false;
            }
        }
     }
     return true;
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
    bool ans = obj.isBipartite(V,adj);
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}