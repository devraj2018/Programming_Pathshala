class Solution {
public:
    vector<vector<int>> res;
    
    void helper(vector<int>& nums,int curr_I,vector<int>curr)
    {
         if(curr_I==nums.size()){
             res.push_back(curr);
             return;
         }
        
        helper(nums,curr_I+1,curr);
        
        curr.push_back(nums[curr_I]);
          helper(nums,curr_I+1,curr);
      
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        int curr_I=0;
        helper(nums,curr_I,curr);
        return res;
    }
};