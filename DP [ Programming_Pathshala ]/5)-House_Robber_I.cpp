class Solution {   // -------------Bottom Up------------//
public:
    int rob(vector<int>& nums) {
       
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
         
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
             dp[i]=max(dp[i-1], nums[i]+dp[i-2]);
            
        }
        return dp[n-1];
    }
};

class Solution          // -----  Top Down--------------//
{
    public:
    vector<int>dp;
    int helper(int arr[],int n)
      { if(n<0) return 0;
        if(n==0) return arr[0];
        if(n==1) return max(arr[0],arr[1]);
      
        if(dp[n]!=-1) return dp[n];
      
      int maxx=INT_MIN;
      if(n-1>=0) maxx=max(maxx,helper(arr,n-1));
      if(n-2>=0) maxx=max(maxx,arr[n]+helper(arr,n-2));
      
      return dp[n]=maxx;
   }
    int FindMaxSum(int arr[], int n)
    {  dp.resize(n,-1);
       return helper(arr,n-1);
    }
};