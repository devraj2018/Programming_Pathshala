class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans=INT_MIN;
        int maxp=1;
        int minp=1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0) swap(maxp,minp);
            
            maxp=max(maxp*nums[i],nums[i]);
            minp=min(minp*nums[i],nums[i]);
            
            ans=max(ans,maxp);
             
        }
        return ans;
        
    }
};