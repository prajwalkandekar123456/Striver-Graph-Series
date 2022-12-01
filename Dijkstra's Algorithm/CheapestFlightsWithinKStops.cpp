//Problem
/*There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input:
n = 4
flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0
dst = 3
k = 1
Output:
700
Explaination:
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/

// Time Complexity : E
// Space Complexity : N*M


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
     
        vector<pair<int,int>> adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src] = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(stops>k) continue;
            for(auto itr:adj[node]){
                int adjNode = itr.first;
                int edW = itr.second;
                if(dis+edW<dist[adjNode])
                {
                    dist[adjNode] = dis+edW;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};


int main() {
   
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    return 0;
}
