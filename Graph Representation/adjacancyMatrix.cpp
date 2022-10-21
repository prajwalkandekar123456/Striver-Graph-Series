#include<bits/stdc++.h>
using namespace std;
// Space Complexity = O(n*n)
int main()
{
    int n,m; // n is nodes and m = edges
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;   
        adj[v][u] = 1;
    }
    for(int i=0;i<m;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}