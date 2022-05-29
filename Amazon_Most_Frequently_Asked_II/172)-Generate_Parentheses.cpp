class Solution {
public:
    vector<string>res;
    void helper(int open_rem,int close_rem,string curr)
    {
        
         if(open_rem==0 && close_rem==0)
         {
             res.push_back(curr);
             return;
         }
         if(open_rem<0 || close_rem<0) return;
         if(open_rem>close_rem) return;
        
         helper(open_rem-1,close_rem,curr+'(');
         helper(open_rem,close_rem-1,curr+')');
        
         
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        int curr_I=0;
        int open=n,close=n;
        
        helper(open,close,curr);
        return res;
    }
};