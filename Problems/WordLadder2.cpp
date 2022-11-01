// Problem
/*Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
The first part of this problem can be found here.


Example 1:

Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".*/

// Time Complexity :
// Space Complexity :

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution{
public:
vector<vector<string>> findSequences(string beginWord,string endWord,vector<string> &wordList)
{
    vector<vector<string>> ans;
    queue<vector<string>> q;
    q.push({beginWord});
    unordered_set<string> st(wordList.begin(),wordList.end());
    vector<string> usedOfLevel;
    int level = 0;
    while(!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();
        if(vec.size()>level)
        {
            level++;
            for(auto it : usedOfLevel)
            {
                st.erase(it);
            }
            usedOfLevel.clear();
        }
        string word = vec.back();
        if(word == endWord)
        {
            if(ans.size() == 0)
            {
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size())
            {
                ans.push_back(vec);
            }
        }
        for(int i = 0;i<word.size();i++)
        {
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++)
            {
               word[i] = ch;
               if(st.count(word)>0)
               {
                 vec.push_back(word);
                 q.push(vec);
                 usedOfLevel.push_back(word);
                 vec.pop_back();
               }
            }
            word[i] = original;
        }  
    }
    return ans;
}
};
int main()
{
    int n;
    cin>>n;
    vector<string> wordList(n);
    for(int i = 0;i<n;i++)
    {
        cin>> wordList[i];
    }
    string beginWord,endWord;
    cin>> beginWord>> endWord;
    Solution obj;
    vector<vector<string>> ans = obj.findSequences(beginWord,endWord,wordList);
    for(int i = 0;i<ans.size();i++)
    {
        for(int j = 0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}