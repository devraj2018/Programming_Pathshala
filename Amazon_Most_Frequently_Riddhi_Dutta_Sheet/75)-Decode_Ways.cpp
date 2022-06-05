class Solution {
public:
    int helper(string &s,int curr_I,  vector<int>&dp)
    {
        if(curr_I==s.length()) return 1;
        
        if(dp[curr_I]!=-1) return dp[curr_I];
        
        int take_one=0;
        if(s[curr_I]>='1' && s[curr_I]<='9') take_one=helper(s,curr_I+1,dp);
        
        int take_two=0;
        if(curr_I+1<s.length())
        {
            string temp="";
            temp+=s[curr_I];
            temp+=s[curr_I+1];
            
            if(temp>="10" && temp<="26") take_two=helper(s,curr_I+2,dp);
        }
        
        return dp[curr_I]=take_one+take_two;
        
        
        
        
    }
    int numDecodings(string s) {
        
        int curr_I=0;
        vector<int>dp(s.length(),-1);
        return helper(s,curr_I,dp);
        
    }
};