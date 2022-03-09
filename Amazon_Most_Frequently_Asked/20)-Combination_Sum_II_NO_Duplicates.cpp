class Solution {
public:
    vector<vector<int>>res;
   
    void helper(int curr_I,int target,int curr_sum,vector<int>&arr, vector<int>curr)
       {
            if(curr_I==arr.size())
               {   if(curr_sum==target) res.push_back(curr);
                   return;
               }
             if(curr_sum>target) return;
          
             helper(curr_I+1,target,curr_sum,arr,curr);
          
             if(curr_I>0 && arr[curr_I]==arr[curr_I-1])
                 return;
           
            curr.push_back(arr[curr_I]);
            helper(curr_I+1,target,curr_sum+arr[curr_I],arr,curr);
              
       }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
          sort(candidates.begin(),candidates.end());
          int n=candidates.size();
          vector<int>curr;
          helper(0,target,0,candidates,curr);
          return res;
        
    }
};