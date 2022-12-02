//Problem
/*
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
*/

//Time Complexity : O(100000*N)
// Space Complexity : O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minimumMultiplications(vector<int> &arr,int start,int end)
    {
        queue<pair<int,int>> q;
        vector<int> dist(100000,1e9);
        q.push({start,0});
        dist[start] = 0;
        int mod  = 100000;
        while(!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(auto it: arr)
            {
                int num = (it*node)%mod;
                if(steps+1<dist[num])
                {
                    dist[num] = steps+1;
                    if(num == end) return steps+1;
                    q.push({num,steps+1});
                }
            }
        }
        return -1;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int start,end;
    cin>>start>>end;
    Solution obj;
    int ans = obj.minimumMultiplications(arr,start,end);
    cout<<ans<<endl;
    return 0;
}