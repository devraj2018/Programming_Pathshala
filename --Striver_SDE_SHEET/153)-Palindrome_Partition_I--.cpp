#include<bits/stdc++.h>
void helper(string &s, int start, vector<vector<string>> &ans, vector<string> &currentList, vector<vector<bool>> &dp) 
{
    if (start >= s.length()) 
     {   ans.push_back(currentList);
         return;
     }

    for (int k = start; k < s.length(); k++) 
        {
          if (dp[start][k]) 
            {
              currentList.push_back(s.substr(start, k + 1 - start));
              helper(s, k + 1, ans, currentList, dp);
              currentList.pop_back();
           }
        }
}

vector<vector<string>> partition(string &s) 
{   vector<vector<string>> ans;
    vector<vector<bool>> dp (s.length(), vector <bool> (s.length(), false));
     
    // Boolean dp for checking substing[i..j] is palindrome or not.
    for (int i = 0; i < s.length(); i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]))   dp[j][i] = true;
         
        }
    }

    vector<string> currentList;
    helper(s, 0, ans, currentList, dp);
    return ans;

}
