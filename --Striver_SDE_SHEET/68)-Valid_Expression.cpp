#include<bits/stdc++.h>
bool isValidParenthesis(string s)
{
   stack<char>stk;
        
        int i=0,n=s.length();
        while(i<n)
        {
              if(s[i]=='(' || s[i]=='{' ||s[i]=='[')
              {
                  stk.push(s[i]);
                  i++;
                  continue;
              }
            
             if(stk.empty()) return false;
            
             if(s[i]==')' && stk.top()=='(')
                 stk.pop();
             else if(s[i]=='}' && stk.top()=='{')
                 stk.pop();
             else if(s[i]==']' && stk.top()=='[')
                 stk.pop();
             else return false;
            i++;
       }
         if(!stk.empty()) return false;
        return true;
}