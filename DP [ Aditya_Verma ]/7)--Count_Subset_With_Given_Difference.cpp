// Let sum of subset 1 be s1 and subset 2 with s2
// s1 - s2 = diff (given)
// s1 + s2=sum of array (logical)
// Therefore adding both eq we get :
// 2s1= diff + sum of array
// s1= (diff + sum of array)/2;
// Problem reduces to find no of subsets with given sum s1
class Solution {
public:
    int count_zero_till_that_index(vector<int>&nums,int start,int end)
    {
        int count=0;
        for(int i=start;i<=end;i++) if(nums[i]==0) count++;
        
        return count;
            
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto x:nums) sum+=x;
        
        if(sum < abs(target)  || (sum+target)%2==1) return 0; ///   ---   Important Base CASE  ---        ///
        
        int needed_sum= (sum+target)/2;
        int n=nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(needed_sum+1));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=needed_sum;j++)
            {
                 if(i==0 && j==0) dp[i][j]=1;
                 else if(i==0) dp[i][j]=0;
                 else if(j==0) dp[i][j]=pow(2,count_zero_till_that_index(nums,0,i-1));
                 else if(nums[i-1]<=j) dp[i][j]=dp[i-1][j]+ dp[i-1][j-nums[i-1]];
                 else dp[i][j]=dp[i-1][j];
                
            }
        }
        return dp[n][needed_sum];
        
    }
};



