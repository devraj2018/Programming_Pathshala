#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int>mp;
    mp[0]=1;
    int ans=0;
    int curr_xor=0;
    for(int i=0;i<arr.size();i++)
    {
        
        curr_xor^=arr[i];
        
        if(mp.find(curr_xor^x)!=mp.end())
        {
            ans+=mp[curr_xor^x];
        }
        mp[curr_xor]++;
    }
    return ans;
}