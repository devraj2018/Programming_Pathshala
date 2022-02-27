class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<int>>mp;
        vector<vector<string>>res;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            
            mp[temp].push_back(i);
        }
        
        for(auto x:mp)
        {
            vector<string>temp;
            for(auto y:x.second)
            {
                temp.push_back(strs[y]);
            }
            res.push_back(temp);
            
        }
        return res;
        
    }
};