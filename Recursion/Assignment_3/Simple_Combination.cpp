class Solution {
public:
    vector<vector<int>> res;
    
    void helper(int n,int k,int currI,vector<int>&curr,int start=1)
    {
         if(currI==k)
         {
             res.push_back(curr);
             return;
         }
         for(int from=start;from<=n;from++)
            {      curr.push_back(from);
                   helper(n,k,currI+1,curr,from+1);
                   curr.pop_back();
            }
        
     }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        helper(n,k,0,curr);
        return res;
        
    }
};