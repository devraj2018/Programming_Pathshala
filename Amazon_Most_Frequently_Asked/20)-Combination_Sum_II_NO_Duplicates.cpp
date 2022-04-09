class Solution {
public:
    vector<vector<int>>res;
    
    void helper(vector<int>&arr,int target,vector<int>&curr_candidate,int curr_sum=0,int curr_I=0)
      {
        if(curr_sum==target) {res.push_back(curr_candidate); return; }
        if(curr_sum>target) return;
        
        for(int i=curr_I;i<arr.size();i++)
            {
                if(i!=curr_I && arr[i]==arr[i-1]) continue;  // To avoid Duplicates
                curr_candidate.push_back(arr[i]);
                helper(arr,target,curr_candidate,curr_sum+arr[i],i+1);
                curr_candidate.pop_back();
            }
       }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,curr);
        return res;
    }
};