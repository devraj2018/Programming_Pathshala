class Solution {
public:
    int count_zero_till_that_index(vector<int>&nums,int i)
    {
        int count=0;
        for(int j=0;j<i;j++) 
        {
            if(nums[j]==0) count++;
        }
        return count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int total_sum=0;
        for(auto x:nums) total_sum+=x;
        
        if(total_sum<abs(target) || (target+total_sum)%2==1) return 0;
        
        int needed_sum= (total_sum+target)/2;
        int n=nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(needed_sum+1));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=needed_sum;j++)
            {
                 if(i==0 && j==0) dp[i][j]=1;
                 else if(i==0) dp[i][j]=0;
                 else if(j==0) dp[i][j]=pow(2,count_zero_till_that_index(nums,i));
                 else if(nums[i-1]<=j) dp[i][j]=dp[i-1][j]+ dp[i-1][j-nums[i-1]];
                 else dp[i][j]=dp[i-1][j];
                
            }
        }
        return dp[n][needed_sum];
        
    }
};