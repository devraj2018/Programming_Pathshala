class Solution {
public:
    
    int fun(string &s,int start,int end,vector<vector<int>>&dp)
    {  
        if(start>=end) return 0;
        
         if(dp[start][end]!=-1)
            return dp[start][end];
       
        
        if(s[start]==s[end])
            return dp[start][end]=fun(s,start+1,end-1,dp);
        
        return dp[start][end]=1+min(fun(s,start+1,end,dp),fun(s,start,end-1,dp));
        
        
    }
    int minInsertions(string s) {
        vector<vector<int>>dp (s.length(),vector<int>(s.length(),-1));
        int e=s.length()-1;
        return fun(s,0,e,dp);
        
    }
};