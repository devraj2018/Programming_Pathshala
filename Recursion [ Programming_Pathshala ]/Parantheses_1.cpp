class Solution {
public:
    //Another variation ->Here we call only those function which will return valid parenthesis//


     void helper2(string curr,vector<string>&all,int open_used,int close_used,int n)
     {
            if(close_used==n)
            {
                all.push_back(curr);
                return ;
            }

            if(close_used < open_used)
             helper2(curr+")" ,all,open_used,close_used+1);

            if(open_used < n)
             helper2(curr + "(" , all, open_used+1,close_used);

     }
    
    void helper(string curr,vector<string>&all,int open,int close,int n)
    {
         if(close>open|| open>n || close>n) return;
         if(open ==n && close==n)
          {
             all.push_back(curr);
             return;
          }
        
         curr+="(";
         helper(curr,all,open+1,close,n);
         curr.pop_back();
         curr+=")";
         helper(curr,all,open,close+1,n);
         curr.pop_back();        
     
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>all;
        string curr="";
        int open_count=0,close_count=0;
        helper(curr,all,open_count,close_count,n);
        return all;
    }
};