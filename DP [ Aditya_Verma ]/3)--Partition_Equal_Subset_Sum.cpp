class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        
        if(sum&1) return false;  // we cannot divide odd sum into two parts
        
        // Now it like Check array whose Subset Sum is equal to sum/2 or not;
        // Thats knapsack variation
        
        int W=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(W+1));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                if(i==0 && j==0 ) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
                else if(j==0) dp[i][j]=1;
                else if(nums[i-1]<=j)
                    dp[i][j]= dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
          }
        }
        return dp[n][W];
         
    }
};