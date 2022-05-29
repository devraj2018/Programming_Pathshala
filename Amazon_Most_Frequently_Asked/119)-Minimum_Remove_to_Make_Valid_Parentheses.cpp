class Solution {
public:
    string minRemoveToMakeValid(string s) {
    
        stack<int>stk;
        
        for(int i=0;i<s.length();i++)
        {
             if(s[i]>='a' && s[i]<='z') continue;
             else if(s[i]=='(') stk.push(i);
             else{
                     if(!stk.empty())
                     {
                         stk.pop();   
                     }
                   else {
                       s[i]='#';   // For extra closing brackets
                   }
               }
        }
        while(!stk.empty())
        {
            s[stk.top()]='#';   // For extra opening brackets
            stk.pop();
        }
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='#') ans+=s[i];
        }
        return ans;
        
       
    }
};