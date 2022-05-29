class Solution {
public:
    vector<vector<int>> res;
    
    void helper(vector<int>& nums,int curr_I,vector<int>curr)
    {
         if(curr_I==nums.size()){
             res.push_back(curr);
             return;
         }
        
        helper(nums,curr_I+1,curr);  // Dont take
        
        int ele=nums[curr_I];
        while(curr_I<nums.size() && ele==nums[curr_I])   // Take All
        {
             curr.push_back(nums[curr_I]);
            curr_I++;
            
        }
        helper(nums,curr_I,curr);
        
       
      
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        int curr_I=0;
        sort(nums.begin(),nums.end());
        helper(nums,curr_I,curr);
        return res;
    }
};