class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxp=1;
         int minp=1;
        
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0) swap(minp,maxp);
            
            maxp=max(nums[i],maxp*nums[i]);
            minp=min(nums[i],minp*nums[i]);
            
            ans=max(ans,maxp);
          }
        return ans;
        
        
    }
};