class Solution {
public:
    // Similar to count subset sum differece
    int count_zero_till_that_index(vector<int>&nums,int i)
    {
        int count=0;
        for(int j=0;j<i;j++)
        {
            if(nums[j]==0) count++;
        }
        return count;
    }
    
    int CountSubsetSum(vector<int>&nums,int sum)
    {    
         int n=nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=pow(2,count_zero_till_that_index(nums,i));
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                 if(nums[i-1]<=j) dp[i][j]=dp[i-1][j-nums[i-1]] + dp[i-1][j];
                 else dp[i][j]=dp[i-1][j];
                
            }
        }
        
      return dp[n][sum];  
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int total_sum=0;
        for(auto x:nums)
            total_sum+=x;
        
        if(total_sum<abs(target) || (total_sum+target)%2==1) return 0;  // Iss case mai answer zero hi hoga
        
        int set_1_sum= (total_sum+target)/2;
        
        return CountSubsetSum(nums,set_1_sum);
        
        
    }
};