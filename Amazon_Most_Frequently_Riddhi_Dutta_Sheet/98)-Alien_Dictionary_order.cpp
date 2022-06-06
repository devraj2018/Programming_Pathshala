class Solution{
    public:
    string findOrder(string words[], int N, int K) {
        
         vector<int>adj[26];
         vector<int>Indegree(26,0);
       
         for(int i=1;i<N;i++)
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
        queue<int>q;
        for(int i=0;i<26;i++) {
            if(Indegree[i]==0) q.push(i);
        }
        
        string ans="";
        while(!q.empty())
        {
             int curr=q.front();
             q.pop();
             
             ans+=(curr+'a');
             
          
            
            for(auto child:adj[curr])
            {
                
                Indegree[child]--;
                 if(Indegree[child]==0) q.push(child);
                
            }
        }
        return ans;
        
    }
};