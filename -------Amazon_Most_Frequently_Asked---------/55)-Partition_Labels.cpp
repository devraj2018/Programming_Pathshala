class Solution {
public:
    vector<int> partitionLabels(string s) {
       
        vector<int>res;
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.length();i++) mp[s[i]]=i;
        
        int i=0,n=s.length();
        while(i<n)
        {
             int length=0;
             int maxx=mp[s[i]];
             
             while(i<n && i<=maxx)
             {
                  maxx=max(maxx,mp[s[i]]);
                  i++;
                  length++;
             }
       
             res.push_back(length);
        }
        return res;
        
        
    }
};