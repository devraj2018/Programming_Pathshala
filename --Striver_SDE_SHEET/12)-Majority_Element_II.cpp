#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &nums)
{
    int n=nums.size();
        int maj1=0,count1=0,maj2=0,count2=0;
        
        
        for(int i=0;i<nums.size();i++)
        {
             if(nums[i]==maj1)
             {
                 count1++;
             }
             else if(nums[i]==maj2)
             {
                 count2++;
             }
             else if(count1==0)
             {
                 maj1=nums[i];
                 count1=1;
             }
            else if(count2==0)
             {
                 maj2=nums[i];
                 count2=1;
             }
            else
            {
                count1--;
                count2--;
            }
         }
        
        count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maj1)
            {
                count1++;
            }
            else if(nums[i]==maj2) count2++;
        }
        
        vector<int>res;
        if(count1>n/3) res.push_back(maj1);
        if(count2>n/3) res.push_back(maj2);
        return res;

}