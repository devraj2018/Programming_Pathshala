#include<bits/stdc++.h>
void helper(vector<int>&v,vector<int>&curr, vector<vector<int>>&res,int curr_I)
{ 
    if(curr_I==v.size())
    {
        res.push_back(curr);
        return;
    }
    
    helper(v,curr,res,curr_I+1);
    
    curr.push_back(v[curr_I]);
    helper(v,curr,res,curr_I+1);
    curr.pop_back();
    
}
vector<vector<int>> pwset(vector<int>v)
{
    sort(v.begin(),v.end());
    vector<int>curr;
    vector<vector<int>>res;
    
    helper(v,curr,res,0);
    return res;
    
}