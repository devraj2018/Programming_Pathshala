class Solution {
public:
    bool isValid(string s) {
        
        if(s.length()<3) return false;
        
        stack<char>stk;
        int i=0,n=s.length();
        while(i<n)
        {
             if(s[i]!='c') stk.push(s[i]);
             else if(stk.size()<2) return false;
             else
                { 
                    
                 if(stk.top()!='b')
                     return false;
                 stk.pop();
                 if(stk.top()!='a')
                     return false;
                 stk.pop();
               
                }
            i++;
         }
        if(stk.empty()) return true;
        return false;
      }
};