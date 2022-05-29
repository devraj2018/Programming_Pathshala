class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int>lastindex;
        
        for(int i=0;i<s.length();i++) lastindex[s[i]]=i;
        
        vector<int>res;
        
        int i=0,start=0,end=s.length();
        
        while(i<end)
        {    int maxx=lastindex[s[i]];
             int j; 
             for(j=i;j<=maxx;j++)
             {
                  maxx=max(maxx,lastindex[s[j]]);
             }
             res.push_back(maxx-i+1);
             i=maxx+1;
             
        }
        return res;
        
    }
};