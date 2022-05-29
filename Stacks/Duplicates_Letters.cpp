class Solution {
public:
    string removeDuplicateLetters(string s) {
      
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++) mp[s[i]]=i;
        
        vector<bool>visited(26,false);
        stack<char>stk;
        
        for(int i=0;i<s.length();i++)
        {
            if(visited[s[i]-'a']) continue;
            
            while(!stk.empty() && stk.top()>=s[i] && mp[stk.top()]>=i)
            {
                char x=stk.top();
                stk.pop();
                
                visited[x-'a']=false;
            }
            
            stk.push(s[i]);
            visited[s[i]-'a']=true;
                
        }
        string res="";
        while(!stk.empty())
        {
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};