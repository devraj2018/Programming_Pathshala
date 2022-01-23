class Solution {
public:
    void find_all(vector<int>& nums,  vector<int>&curr, vector<vector<int>>&all_set,int curr_I)
    {    if(curr_I==nums.size())
          {
          all_set.push_back(curr);
           return;
          }
          
          find_all(nums,curr,all_set,curr_I+1);
          
          curr.push_back(nums[curr_I]);
          find_all(nums,curr,all_set,curr_I+1);
          curr.pop_back();
        
    }
            //-------- Array must be in sorted order--  O(n*2^n)   --------//
    void find_lexographic(vector<int>&nums,vector<int>&curr,vector<vector<int>>&all_set,int curr_I=-1)
    {
         if(curr_I==nums.size())
         return;

         all_set.push_back(curr);

         for(int i=curr_I+1;i<nums.size();i++)
         {
             curr.push_back(nums[i]);

             find_lexographic(nums,curr,all_set,i);

             curr.pop_back();

         }



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>all_set;
        int n=nums.size();
        find_all(nums,curr,all_set,0);
        return all_set;
        
    }
};