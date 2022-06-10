#include<bits/stdc++.h>
void helper(vector<int> &num,int curr_I,int sum,vector<int> &res)
{
     if(curr_I==num.size())
     {
         res.push_back(sum);
         return;
     }
     
    helper(num,curr_I+1,sum,res);
    
    helper(num,curr_I+1,sum+num[curr_I],res);
    
    
    
}
vector<int> subsetSum(vector<int> &num)
{    
    vector<int>res;
    int curr_I=0;
    int sum=0;
    helper(num,curr_I,sum,res);
    sort(res.begin(),res.end());
    return res;
}