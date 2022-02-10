class Solution {
  public:
    int findMaxLen(string s) {
        stack<int>stk;
        int maxx=0;
        
        stk.push(-1);
        for(int i=0;i<s.length();i++)
        {
             if(s[i]=='(')
               stk.push(i);
             else
             {
                 stk.pop();
                  if(stk.empty())
                    {
                     stk.push(i);   
                    }
                    else
                         maxx=max(maxx,i-stk.top());
                  
              }
        }
        return maxx;
    }
};