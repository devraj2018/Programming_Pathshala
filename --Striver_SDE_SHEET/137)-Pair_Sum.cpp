#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &nums, int s){
    vector<vector<int>>res;
    sort(nums.begin(),nums.end());
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++)
    {
        if(mp.find(s-nums[i])!=mp.end())
        {
            int c=mp[s-nums[i]];
            while(c--)
            res.push_back({s-nums[i],nums[i]});
            
        }
        
            mp[nums[i]]++;
        
        
    }
   sort(res.begin(),res.end());
    return res;
}