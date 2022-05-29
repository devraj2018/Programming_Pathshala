class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size()==1) return;
        int n=nums.size();
        int k,l;
        for(k=n-2;k>=0;k--)
        {
             if(nums[k]<nums[k+1]) break;
        }
        
        
        if(k<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(l=n-1;l>k;l--)
        {
             if(nums[k]<nums[l]) break;
            
            
        }
        swap(nums[l],nums[k]);
        
        reverse(nums.begin()+k+1,nums.end());
        
    }
};