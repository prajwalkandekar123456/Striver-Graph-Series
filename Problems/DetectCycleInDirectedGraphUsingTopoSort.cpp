#include<bits/stdc++.h>
using namespace std;
// Space COmplexity : O(N)
// Time Complexity : O(V+E)
class Solution{
public:
    bool isCycle(int V,vector<int> adj[])
    {
        int indegree[V] = {0};
        for(int i = 0;i<V;i++)
        {
            for(auto it: adj[i])
            {
               indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<V;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(count == V) return false;
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
    }
    Solution obj;
    bool ans = obj.isCycle(V,adj);
    if(ans) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}