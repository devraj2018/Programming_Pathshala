class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int n=nums.size();
        if(n==1)
            return 0;
        while(low<=high)
        {
              int mid= high -(high-low)/2;
              if(mid==0)
              {    if(nums[0]>nums[1]) return 0;
                   else return 1;
              }
              else if(mid==n-1)
              {    if(nums[n-1]>nums[n-2]) return n-1;
                   else return n-2;
              }
             else
              {
                 if(nums[mid-1]< nums[mid] && nums[mid]>nums[mid+1])
                     return mid;
                 else if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1])
                    low=mid+1;
                 else 
                     high=mid-1;
             }
        }
        return 0;
          
    }
};