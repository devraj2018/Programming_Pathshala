class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
         int maxx=INT_MIN;
         int maxp=1;
         int minp=1;
        
        for(int i=0;i<nums.size();i++)
        {
            
             if(nums[i]<0) swap(maxp,minp);
            
              maxp=max(nums[i],nums[i]*maxp);
              minp=min(nums[i],nums[i]*minp);
            
             maxx=max(maxx,maxp);
            
            
        }
        return maxx;
        
    }
};