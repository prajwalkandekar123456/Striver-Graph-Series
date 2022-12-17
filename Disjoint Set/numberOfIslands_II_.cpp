// Problem

/*
You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.

 

Example 1:

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
*/

// Time Complexity :
// Space Complexity :


#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
  public:
    vector<int> parent,size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<=n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        vector<int > ans;
        int cnt = 0;
        for(auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            
            int delrow[] = {-1,0,+1,0};
            int delcol[] = {0,+1,0,-1};
            for(int i = 0;i<4;i++)
            {
                int newr = delrow[i]+row;
                int newc = delcol[i]+col;
                if(newr>=0 && newr<n && newc>=0 && newc<m)
                {
                    if(vis[newr][newc] == 1)
                    {
                        int nodeNo = row*m+col;
                        int adjNodeNo  = newr*m+newc;
                        if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo))
                        {
                            cnt--;
                            ds.unionBySize(nodeNo,adjNodeNo);
                        }
                    }
                    
                }
            }
            ans.push_back(cnt);
            
        }
        return ans;
    }
};

int main() {

        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
}

