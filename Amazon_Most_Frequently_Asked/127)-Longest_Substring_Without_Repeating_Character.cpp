
====================================================================================
==============   Optimised using hashmap =============================================
====================================================================================

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxx=0;
        int start=-1;
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.length();i++)
        {
             if(mp.find(s[i])!=mp.end() && mp[s[i]]>start)
             {
                 start=mp[s[i]];
             }
            
            maxx=max(maxx,i-start);
            mp[s[i]]=i;
            
        }
        return maxx;
    }
};




====================================================================================
==============   Brute force O(n*256) =============================================
====================================================================================
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        int maxx=0;
         unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {   int j ;
             for(j=i;j<s.length();j++)
             {
                 if(mp.find(s[j])!=mp.end()) break;
                 
                 mp[s[j]]++;
             }
            maxx=max(maxx,j-i);
            mp.clear();
        }
        return maxx;
    }
};