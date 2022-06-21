#include<bits/stdc++.h>
bool wordBreak(vector < string > & wordDict, int n, string & s) {
     
        if(wordDict.size()==0)  return false;
       
        vector<bool>dp(s.size()+1,false);
        dp[0] = true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])            
                {
                    string word = s.substr(j,i-j);
                    auto it = find(wordDict.begin(),wordDict.end(),word);
                    if(it!=wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
}






============================= Time Complexity  : O(N ^ 2) ==========================================================
=============================  Space Complexity : O(N)   ==========================================================
 
 

#include <bits/stdc++.h>
unordered_set < string > hashMap;

bool wordBreakHelper(string & s, int start, vector < int > & dp) {
   
    if (start == s.size())  return dp[start] = 1;
    
    if (dp[start] != -1) return dp[start];
     
    for (int i = start + 1; i <= s.size(); i++) {
          if (hashMap.find(s.substr(start, i - start)) != hashMap.end()) {
            if (wordBreakHelper(s, i, dp)) {
                return dp[start] = 1;
            }
        }
    }

    
    return dp[start] = 0;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    
    hashMap.clear();
    for (string s: arr) hashMap.insert(s);
    vector < int > dp(target.size() + 1, -1);
    return wordBreakHelper(target, 0, dp);
}