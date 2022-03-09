class Solution {
public:
    vector<vector<int>>res;
    
    void subset(vector<int>&nums,int curr_I,vector<int>curr)
    {
         if(curr_I==nums.size())
         {
             res.push_back(curr);
             return;
         }
        
         subset(nums,curr_I+1,curr);        // Dont take
        
         while(curr_I<nums.size()-1 && nums[curr_I]==nums[curr_I+1])  //Take all 
         {
             curr.push_back(nums[curr_I]);   
             curr_I++;
         }
          curr.push_back(nums[curr_I]);
          subset(nums,curr_I+1,curr);          //  and call for next
        
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        sort(nums.begin(),nums.end());
        subset(nums,0,curr);
        return res;
    }
};