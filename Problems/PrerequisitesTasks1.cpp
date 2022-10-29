// Problem
/*There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.


Example 1:

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.*/

// Time Complexity : O(n+N)
// Space Complexity : O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isPosiible(int N,vector<pair<int,int>> &prerequisites)
    {
        vector<int> adj[N];
        for(auto it: prerequisites)
        {
            adj[it.first].push_back(it.second);
        }
        int indegree[N] = {0};
        for(int i = 0;i<N;i++)
        {
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for(int i = 0;i<N;i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == N) return true;
        return false;
    }
};
int main()
{
    int N,P;
    cin>>N>>P;
    vector<pair<int,int>> prerequiites;
    for(int i = 0;i<P;i++)
    {
        int x,y;
        cin>>x>>y;
        prerequiites.push_back({x,y});
    } 
    Solution obj;
    bool ans = obj.isPosiible(N,prerequiites);
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;  
    return 0;
}