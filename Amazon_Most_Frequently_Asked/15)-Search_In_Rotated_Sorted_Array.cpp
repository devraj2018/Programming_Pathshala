class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1,mid;
        
        while(low<high)
        {
            mid= low+(high-low)/2;
            
            if(nums[mid]==target) return mid;
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid;
        }
        int pivot=low;
        low=0,high=n-1;
        while(low<=high)
        {
             mid= low+(high-low)/2;
             int realmid= (mid+pivot)%n;
            
             if(nums[realmid]==target) return realmid;
            
             if(nums[realmid]>target) high=mid-1;
             else low=mid+1;
            
            
        }
        return -1;
    }
};