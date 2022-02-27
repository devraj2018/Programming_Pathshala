class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxx=1;
        for(int i=0;i<n;i++)
        {  
            for(int j=i-1;j>=0;j--)
            {  if(nums[i]>nums[j] && dp[j]+1>dp[i])
                 {dp[i]=dp[j]+1;
                  maxx=max(maxx,dp[i]);
                  }   
            }
             
        }
        
        
       return maxx; 
    }
};