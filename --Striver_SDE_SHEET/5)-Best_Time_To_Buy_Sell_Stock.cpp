#include <bits/stdc++.h> 
int maximumProfit(vector<int> &nums){
        int maxx=0;
        int minn=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            maxx=max(maxx,nums[i]-minn);
            minn=min(minn,nums[i]);
        }
        return maxx;
}