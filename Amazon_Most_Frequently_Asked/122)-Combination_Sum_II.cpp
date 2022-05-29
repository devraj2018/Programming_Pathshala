class Solution {
public:
     vector<vector<int>>res;
    void helper(vector<int>& candidates,int target,int curr_I, vector<int>curr,int curr_Sum=0)
    { 
           if(curr_Sum>target) return;
           if(curr_Sum==target)
            {
                res.push_back(curr);
                 return;
            }
           if(curr_I==candidates.size()) return;
        
         helper(candidates,target,curr_I+1,curr,curr_Sum);  // Dont take
        
        
          int ele=candidates[curr_I]; 
          while(curr_I<candidates.size() && ele ==candidates[curr_I] )  // take all
          {    curr_Sum+=candidates[curr_I];
               curr.push_back(candidates[curr_I]);
               curr_I++;
          }
          helper(candidates,target,curr_I,curr,curr_Sum); 
          
              
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        int curr_I=0;
        helper (candidates, target,curr_I,curr);
        return res;
    }
};