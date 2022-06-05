==========================================================================================================
========================================= Bottom Up DP O(n)Time and O(1)Space ============================
==========================================================================================================

++++++++++    Same as House Robber I, trick here is to exclude first or last ele ++++++++++++++
class Solution {
public:
     int robber(vector<int>& nums,int start,int end) {
        
         int a=nums[start];
         int b=max(nums[start],nums[start+1]);
         int c=max(nums[start],nums[start+1]);
        
         for(int i=start+2;i<=end;i++)
         {
             c=max(nums[i]+a,b);
             a=b;
             b=c;
         }
        return c;
        
    }
    int rob(vector<int>& nums) {
        
         int n=nums.size();
         
         if(n==1) return nums[0];
         if(n==2) return max(nums[0],nums[1]);
        
         return max(robber(nums,0,n-2),robber(nums,1,n-1));
        
    }
};