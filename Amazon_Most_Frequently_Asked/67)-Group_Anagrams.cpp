class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n=strs.size();
        vector<vector<string>>res;
        vector<pair<string,int>>temp;
        
        for(int i=0;i<n;i++)
          {
            string s=strs[i];
            sort(s.begin(),s.end());
            temp.push_back({s,i});
          }
        sort(temp.begin(),temp.end());
        int i=0;
        while(i<n)
           { 
              vector<string>v;
              string ss=temp[i].first;
              while(i<n && ss == temp[i].first)
                {
                  v.push_back(strs[temp[i].second]);
                  i++;
                }
            res.push_back(v);
           }
        return res;
          
    }
};