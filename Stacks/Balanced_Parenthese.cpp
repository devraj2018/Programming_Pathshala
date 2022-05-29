class Solution {
public:
    bool isValid(string s) {
        if((s.length())&1) return false;
        stack<char>st;
        int i=0;
        while(i<s.length())
        {
              if(s[i]=='(' || s[i]=='{' ||s[i]=='[')
                  st.push(s[i]);
              else{
                  
                  if(st.empty()) return false;
                  
                  
                  if(st.top()== '(' && s[i]==')')
                      st.pop();
                  else if(st.top()== '{' && s[i]=='}')
                      st.pop();
                  else if(st.top()== '[' && s[i]==']')
                      st.pop();
                  else return false;
                  }
            i++;
        }
        if(st.empty()) return true;
        return false;
        
    }
};