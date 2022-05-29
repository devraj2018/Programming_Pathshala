class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>stk;
        stk.push(-1);
        int n=s.length();
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') stk.push(i);
            else
            {
                 stk.pop();
                 if(!stk.empty())
                 {
                     maxx=max(maxx,i-stk.top());
                 }
                else
                    stk.push(i);
           }
            
        }
        return maxx;
    }
};