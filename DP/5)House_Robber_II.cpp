class Solution {
public:
    
    int robber(vector<int>&nums,int start,int end)
    {
         int n=nums.size();
         vector<int>dp(n);
        
          dp[start]=nums[start];
          dp[start+1]=max(nums[start],nums[start+1]);
        
         for(int i=start+2;i<end;i++)
         {
             dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
         }
        
        return dp[end-1];
   }
    int rob(vector<int>& nums) {
        
        
       
        int n=nums.size();
        if(n==1 ) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
       int  ans=max(robber(nums,1,n),robber(nums,0,n-1));
        return ans;
        
    }
};