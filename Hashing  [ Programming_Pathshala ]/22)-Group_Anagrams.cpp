class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>>temp;
        vector<vector<string>>res;
         
        
        for(int i=0;i<strs.size();i++)
        {  
            string s=strs[i];
            sort(s.begin(),s.end());
             
            temp.push_back({s,i});
        }
        sort(temp.begin(),temp.end());
        int n=temp.size();
        int i=0;
        while(i<n)
        {    vector<string>curr;
             string t=temp[i].first;
            
              while(i<n && t== temp[i].first)
                 { curr.push_back(strs[temp[i].second]);
                 i++;
                 }
             
              res.push_back(curr);
       }
        return res;
        
    }
};