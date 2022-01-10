class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto x:words)
          mp[x]++;
        int l=words[0].length();
        int window= (words.size())*l;
        int n=s.length();
        vector<int>res;
        
        for(int i=0;i<=n-window;i++)
        {   unordered_map<string,int>temp=mp;      // Keep in mind this part ->crux of this question
            int j=i;
            bool flag=true;
            while(j<window+i)
            {   string ss=s.substr(j,l);
                if(temp.find(ss)==temp.end() || temp[ss]==0)
                {
                    flag=false;
                    break;
                }
               temp[ss]--;
               j+=l;
           }
            if(flag)
                res.push_back(i);
            
        }
        return res;
        
    }
};