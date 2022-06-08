#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
     vector<int>res;
        deque<int>decreasing;
        
        for(int i=0;i<k;i++)
        {
            while(!decreasing.empty() && nums[decreasing.back()]<=nums[i])
                decreasing.pop_back();
            
            decreasing.push_back(i);
        }
        
        res.push_back(nums[decreasing.front()]);
        
        for(int i=k;i<nums.size();i++)
        {
            while(!decreasing.empty() && nums[decreasing.back()]<=nums[i])
                decreasing.pop_back();
            
            decreasing.push_back(i);
            
            if(i-decreasing.front()>=k) decreasing.pop_front();
            
            res.push_back(nums[decreasing.front()]);
            
        }
        return res;
        
}