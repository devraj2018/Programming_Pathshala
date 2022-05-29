class Solution {
public:
    int helper(string &s,int curr_I,vector<int>&dp)
    {
         if(curr_I==s.length()) return 1;
         if(curr_I>s.length()) return 0;
        
         if(dp[curr_I]!=-1) return dp[curr_I];
        
         int taking_one=0,taking_two=0;
        
         if(s[curr_I]!='0') taking_one= helper(s,curr_I+1,dp);
    
         if(curr_I<s.length()-1)
           {
              string temp="";
              temp+=s[curr_I];
           
              temp+=s[curr_I+1];
             
              if(temp>="10" && temp<="26") taking_two=helper(s,curr_I+2,dp);
          }
         return dp[curr_I]=taking_one+taking_two;
         
    }
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
        return helper(s,0,dp);
        
    }
};