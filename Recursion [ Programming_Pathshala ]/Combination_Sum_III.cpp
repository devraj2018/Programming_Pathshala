class Solution {
public:
    int limit=9;
    vector<vector<int>> res;
    
    void helper(int target,int k,vector<int>&curr,int curr_sum=0,int curr_I=0,int start=1)
    {
        if(curr_I==k)
           {   
              if(curr_sum==target)
                {
                 res.push_back(curr);
                }
             return;
           }
         for(int from=start;from<=limit;from++)
           {  
              curr_sum+=from;
              curr.push_back(from);
              helper(target,k,curr,curr_sum,curr_I+1,from+1);
              
              curr.pop_back();
              curr_sum-=from;
             
           }
       
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        helper(n,k,curr);
        return res;
        
    }
};