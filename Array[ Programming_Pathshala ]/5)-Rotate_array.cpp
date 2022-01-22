class Solution {
public:
    // Method 1--Using Extra space--Easy//
    
    //Method- 2// 
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n)
         k=k%n;
        
       int start=0,end=n-k-1;
        while(start<=end)
        {
            swap(nums[start],nums[end]);
            start++;end--;
        }
        start=n-k;end=n-1;
        while(start<=end)
        {
            swap(nums[start],nums[end]);
            start++;end--;
        }
        start=0,end=n-1;
        while(start<=end)
        {
            swap(nums[start],nums[end]);
            start++;end--;
        }
       
    }
};