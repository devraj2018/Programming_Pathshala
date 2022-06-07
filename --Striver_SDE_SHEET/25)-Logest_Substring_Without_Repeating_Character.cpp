#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
   int maxx=0;
    unordered_map<char,int>mp;
    int start=0;
    for(int i=0;i<input.length();i++)
    {
         if(mp.find(input[i])!=mp.end() && mp[input[i]]>=start)
         {
             start=mp[input[i]]+1;
         }
        
        maxx=max(maxx,i-start+1);
        mp[input[i]]=i;
        
    }
    return maxx;
}