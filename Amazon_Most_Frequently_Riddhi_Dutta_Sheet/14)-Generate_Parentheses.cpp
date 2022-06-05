class Solution {
public:
       vector<string> res;
    void helper(int open,int close,string &curr)
    {
         if(open==0 && close==0)
           {
             res.push_back(curr);
             return;
           }
         if(open<0 || close<0 || close<open) return;
        
          curr+="(";
          helper(open-1,close,curr);
          curr.pop_back();
        
          curr+=")";   
          helper(open,close-1,curr);
         curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        
     
        string curr="";
        int open=n,close=n;
        
        helper(open,close,curr);
        return res;
        
    }
};