class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++)
            {  
             if(nums[i]<=0 || nums[i]>n || nums[i]==i+1)
                 continue;
             int curr_ele=nums[i];
             swap(nums[i],nums[nums[i]-1]);
             if(nums[i]!=curr_ele)   //  This condtion to avoid tle,when we have both ele are equal
               i--;
            
            }
        
        for(int i=0;i<n;i++)
          {
            if(nums[i]!=i+1)
               return i+1;
          }
        return n+1;
       
    }
};