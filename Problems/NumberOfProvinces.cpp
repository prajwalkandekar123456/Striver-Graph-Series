/** Problem :
 Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
**/

#include<bits/stdc++.h>
using namespace std;
// Space Complexity =  O(N)+O(N) == O(N)
// Time Complexity = O(N) + O(V+2E)
class Solution{
    private:
      void dfs(int node,int vis[],vector<int> adjList[])
      {
        vis[node] = 1;
        for(auto it : adjList[node])
        {
            if(!vis[it]){
                dfs(it,vis,adjList);
            }
        }
      }
    public:
      int numProvinces(vector<vector<int>> &adj,int V)
      {
        int vis[V] = {0};
        vector<int> adjList[V];
        for(int i=0;i<V;i++)
        {
            for(int j = 0;j<V;j++)
            {
                if(adj[i][j] == 1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0;i<V;i++)
        {
            if(vis[i] == 0)
            {
                dfs(i,vis,adjList);
                count++;
            }
        }
        return count;
      }
};

int main()
{
    
    int V,x;
    cin>> V;
    vector<vector<int>> adj;
    for(int i=0;i<V;i++)
    {
        vector<int> temp;
        for(int j=0;j<V;j++)
        {
            cin>>x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }
    Solution obj;
    cout<<obj.numProvinces(adj,V)<<endl;
    return 0;
}