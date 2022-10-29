//Problem
/*There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0.


Example 1:

Input:
n = 2, m = 1
prerequisites = {{1, 0}}
Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible order is [0, 1].*/
// Time Complexity : O(N+E)
// Space Complexity : O(N)


#include <bits/stdc++.h>
using namespace std;



class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
         vector<int> adj[n];
        for(int i = 0; i < m; i++) {
            int u = pre[i][1];
            int v = pre[i][0];
            
            adj[u].push_back(v);
        }
        
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++)
            for(int it: adj[i])
                indegree[it]++;
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(q.empty() == false) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it: adj[curr]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(ans.size() == n) return ans;
        else return {};
    }
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
    return 0;
} 