class Solution {
public:
    vector<vector<int>>res;
    vector<int>curr;
    void helper(vector<int>&nums,int curr_I)
    {
         if(curr_I== nums.size())
           {
              res.push_back(curr);
              return;
          }
          helper(nums,curr_I+1);
          
          curr.push_back(nums[curr_I]);
          helper(nums,curr_I+1);
          curr.pop_back();
      }
    vector<vector<int>> subsets(vector<int>& nums) {
         helper(nums,0);
        return res;
        
    }
};