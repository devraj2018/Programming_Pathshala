 
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