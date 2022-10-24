
// Problem
/** An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.**/

// Time Complexity = O(N*M)
// Space Complexity = O(N*M)+O(N*M)
#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
    void dfs(int sr,int sc,int newColor,vector<vector<int>>&ans,vector<vector<int>>image,int delrow[],int delcol[],int iniColor)
    {
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0;i<4;i++)
        {
            int nrow = sr+delrow[i];
            int ncol = sc+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=newColor && ans[nrow][ncol] == iniColor ){
                dfs(nrow,ncol,newColor,ans,image,delrow,delcol,iniColor);
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        dfs(sr,sc,newColor,ans,image,delrow,delcol,iniColor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	
	return 0;
}
