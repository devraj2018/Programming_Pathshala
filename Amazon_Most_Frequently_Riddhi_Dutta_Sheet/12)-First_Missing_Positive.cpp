class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==i+1 || nums[i]<=0 || nums[i]>n) continue;
            
            int index=nums[i]-1;
            swap(nums[i],nums[index]);
            
            if(nums[i]!=nums[index]) i--;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!= i+1) return i+1;
        }
        return n+1;
        
    }
};