class Solution {
public:
     vector<vector<int>>res;
     void helper(vector<int>& candidates, int &target,int curr_sum,vector<int>curr,int curr_I)
     {
          if(curr_I==candidates.size())
          {
               if(curr_sum==target)
               {
                   res.push_back(curr);
               }
              return;
          }
         
         if(curr_sum> target) return;
         
         helper(candidates,target,curr_sum,curr,curr_I+1);
         
         curr.push_back(candidates[curr_I]);
         helper(candidates,target,curr_sum+candidates[curr_I],curr,curr_I);
         
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        int curr_sum=0;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,curr_sum,curr,0);
        return res;
    }
};