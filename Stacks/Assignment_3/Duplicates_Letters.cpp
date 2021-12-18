class Solution {
public:
    string removeDuplicateLetters(string s) {
    
        stack<char>stk;
        stk.push(s[0]);
        unordered_map<char,int>mp;
        unordered_set<char> st;
        st.insert(s[0]);
        for(int i=0;i<s.length();i++)  mp[s[i]]=i;
        
        for(int i=1;i<s.length();i++)
        {   
            if(st.find(s[i])!=st.end()) continue;
            
            while(!stk.empty() && stk.top()>=s[i] && mp[stk.top()]>i) 
               { st.erase(stk.top());
                 stk.pop();
               }
            
            stk.push(s[i]);
            st.insert(s[i]);
        }
        string ans="";
        while(!stk.empty())
        {
            char x=stk.top();
             stk.pop();
             ans= x+ans;
        }
        return ans;
    }
};