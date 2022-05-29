class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
         vector<string>res;
        unordered_map<string,int>mp;
        if(n<10) return {};
        
        for(int i=0;i<=n-10;i++)
        {
            string temp=s.substr(i,10);
            mp[temp]++;
        }
        for(auto ele:mp)
        {
            if(ele.second >1)
                res.push_back(ele.first);
        }
        return res;
        
        
    }
};