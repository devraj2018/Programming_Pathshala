#include<bits/stdc++.h>
void fun(int i,vector<int>arr,vector<int>&subset,vector<vector<int>>&ans)
    {
        if(i==arr.size())
        {
            ans.push_back(subset);
            return;
        }
    
        //include current element
        subset.push_back(arr[i]);
        fun(i+1,arr,subset,ans);
        
        //exclude current element 
        subset.pop_back();
        
        //now its time to not repeat same current value used
        
        while(i+1 < arr.size() && arr[i]==arr[i+1])
        {
            i++;
        }
        
        fun(i+1,arr,subset,ans);
        
    }
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
   sort(arr.begin(),arr.end());
   vector<vector<int>>res;
   vector<int>curr;
   fun(0,arr,curr,res);
   sort(res.begin(),res.end());
       return res;
    
}