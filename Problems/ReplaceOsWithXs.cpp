// Problem
/*Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. */

// Time Complexity = O(N*M)
// Space Complexity = O(N*M)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat,int delrow[],int delcol[])
    {
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col] = 1;
        for(int i = 0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow,ncol,vis,mat,delrow,delcol);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        //For first row
        for(int j = 0;j<m;j++)
        {
            if(!vis[0][j] && mat[0][j] == 'O')
            {
                dfs(0,j,vis,mat,delrow,delcol);
            }
        }
        //for last row
        for(int j = 0;j<m;j++)
        {
            if(!vis[n-1][j] && mat[n-1][j] == 'O')
            {
                dfs(n-1,j,vis,mat,delrow,delcol);
            }
        }
        //first column
        for(int i = 0;i<n;i++)
        {
            if(!vis[i][0] && mat[i][0] == 'O')
            {
                dfs(i,0,vis,mat,delrow,delcol);
            }
        }
        // Last column
        for(int i = 0;i<n;i++)
        {
            if(!vis[i][m-1] && mat[i][m-1] == 'O')
            {
                dfs(i,m-1,vis,mat,delrow,delcol);
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(!vis[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
        
    
    }
};

//{ Driver Code Starts.

int main(){
    
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    return 0;
}
// } Driver Code Ends