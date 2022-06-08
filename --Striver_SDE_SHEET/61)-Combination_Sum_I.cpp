class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>& candidates,vector<int>& curr,int target,int n,int curr_sum=0)
    {
        
        if(n==0)
        {
            if(curr_sum==target)
            {
                res.push_back(curr);
            }
            return;
        }
        
        if(curr_sum>target) return;
        
        //Exclude
        helper(candidates,curr,target,n-1,curr_sum);
        
        //Include
        curr.push_back(candidates[n-1]);
        helper(candidates,curr,target,n,curr_sum+candidates[n-1]);
        curr.pop_back();
          
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.rbegin(),candidates.rend());
        vector<int>curr;
        helper(candidates,curr,target,n);
        return res;
    }
};