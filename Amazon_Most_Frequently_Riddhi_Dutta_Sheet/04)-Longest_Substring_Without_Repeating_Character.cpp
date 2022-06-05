class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mp;
         int maxx=0;
         int start=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=start)
            {
                start=mp[s[i]]+1;
            }
            
            maxx=max(maxx,i-start+1);
            mp[s[i]]=i;
            
         }
        return maxx;
        
    }
};