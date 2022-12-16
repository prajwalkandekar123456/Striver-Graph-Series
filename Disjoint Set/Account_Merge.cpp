// Problem
/*
Given a list of accounts where each element accounts [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.

Note: Accounts themselves can be returned in any order.
 

Example 1:

Input:
N = 4
accounts [ ] =
[["John","johnsmith@mail.com","john_newyork@mail.com"],
["John","johnsmith@mail.com","john00@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]
Output:
[["John","john00@mail.com","john_newyork@mail.com", "johnsmith@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as
they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none
of their email addresses are used by other accounts.
We could return these arrays in any order, for example,
the answer [['Mary', 'mary@mail.com'],
['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com',
'johnsmith@mail.com']]
would still be accepted.
*/

//Time complexity : O(4 * alpha) == O(contant) + (n*m)
// Space Complexity : O(N * M)

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
      if(ulp_u == ulp_v) return ;
      if(size[ulp_u]<size[ulp_v])
      {
          parent[ulp_u] = ulp_v;
          size[ulp_v]+=size[ulp_u];
      }
      else{
          parent[ulp_v] = ulp_u;
          size[ulp_u]+=ulp_v;
      }
  }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mapMailNode;
        for(int i = 0;i<n;i++)
        {
            for(int j = 1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto it : mapMailNode)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergeMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0;i<n;i++)
        {
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
}