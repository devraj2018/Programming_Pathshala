class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        vector<int>adj[26];
        if(words.size()==1) return true;
        vector<int>Indegree(26,0);
        for(int i=1;i<words.size();i++)
        {
            string s1=words[i-1];
            string s2=words[i];
            
            int n1=s1.length();
            int n2=s2.length();
            
            for(int j=0;j<min(n1,n2);j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    Indegree[s2[j]-'a']++;
                    break;
                }
                
            }
            
        }
        
        for(int i=0;i<order.length();i++)
        {
            
            if(Indegree[order[i]-'a']!=0) return false;
            
            for(auto child:adj[order[i]-'a'])
            {
                Indegree[child]--;
            }
            
            
            
        }
        return true;
        
        
        
        
    }
};