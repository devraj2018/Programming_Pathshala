class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        vector<int>adj[26];
        vector<int>Indegree(26,0);
        
        for(int i=0;i<N-1;i++)
            {
                string word1=dict[i]; int n1=word1.length();
                string word2=dict[i+1]; int n2=word2.length();
            
                for(int j=0;j<(min(n1,n2));j++)
                   {
                       if(word1[j]!=word2[j])
                          {
                             adj[word1[j]-'a'].push_back(word2[j]-'a');
                             Indegree[word2[j]-'a']++;
                             break;
                          }
                   }
            }
        
        
        queue<int>q;

        for(int i=0;i<26;i++) if(Indegree[i]==0) q.push(i);
      
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