#include<bits/stdc++.h>
void helper(vector<int> &arr,int target,int curr_I,vector<int>&curr, vector<vector<int>>&res,int n,int curr_sum=0)
{
     if(curr_I==n)
     {
         if(curr_sum==target)
         {
             res.push_back(curr);
         }
         return;
     }
    
    if(curr_sum>target) return;
   
    //Include ALL
    int start=curr_I;
    int curr_ele=arr[curr_I];
    while(curr_I<n && curr_ele==arr[curr_I])
    {
        curr_sum+=arr[curr_I];
        curr.push_back(arr[curr_I]);
        curr_I++;
    }
    
    helper(arr,target,curr_I,curr,res,n,curr_sum);
     
    curr_ele=curr[curr.size()-1];
    while( curr_ele==curr[curr.size()-1])
    {
        curr_sum-=curr_ele;
        curr.pop_back();
        
    } 
    //Exclude
    
    helper(arr,target,start+1,curr,res,n,curr_sum);
      
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{   vector<vector<int>>res;
    vector<int>curr;
    int curr_sum=0;
	sort(arr.begin(),arr.end());
    helper(arr,target,0,curr,res,n);
    return res;
}
