class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string ans="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)  mp[s[i]]=i;
        stack<char>stk;
         vector<bool>vis(26,false);
        
         for(int i=0;i<s.length();i++)
            {
              if(vis[s[i]-'a']) continue;
            
              while(!stk.empty() && stk.top()>=s[i] && mp[stk.top()]>=i)
              {   char x=stk.top();
                  stk.pop();
                  vis[x-'a']=false;
              }
               stk.push(s[i]);
               vis[s[i]-'a']=true;
          }
        while(!stk.empty())
            {
              ans.push_back(stk.top());
              stk.pop();
           }
        reverse(ans.begin(),ans.end());
        return ans;
     }
};