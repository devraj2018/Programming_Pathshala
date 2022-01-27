// Given a string s, remove duplicate letters so that every letter appears once and only once.
// You must make sure your result is the smallest in lexicographical order among all possible results.
/*
Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"

*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        
         unordered_map<char,int>mp;
         for(int i=0;i<s.length();i++) mp[s[i]]=i;
   
         vector<bool>visited(26,false);
         stack<char>st;
         st.push(s[0]);
         visited[s[0]-'a']=true;
         
        for(int i=1;i<s.size();i++)
            {
              if(visited[s[i]-'a']==true) continue;
            
               while(!st.empty() && st.top()>s[i] && mp[st.top()]>i)
                 {
                  visited[st.top()-'a']=false;
                  st.pop();
                }
             
              st.push(s[i]);
              visited[s[i]-'a']=true;
            
           }
        
        string ans="";
        while(!st.empty())
           {
            ans.push_back(st.top());
            st.pop();
          }
        
        reverse(ans.begin(),ans.end()); // To convert smallest from larget lexiographic order
        return ans;
      
    }
};