class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
          vector<int>adj[26];
          vector<int>Indegree(26,0);
          for(int i=1;i<N;i++)
             {
              string s1=dict[i-1];
              string s2=dict[i];
             
               for(int j=0;j<min(s1.length(),s2.length());j++)
                {
                    if(s1[j]!=s2[j])
                      {
                         adj[s1[j]-'a'].push_back(s2[j]-'a');
                         Indegree[s2[j]-'a']++;
                         break;
                      }
                }
              }
        
         string res="";
         queue<int>q;
         for(int i=0;i<26;i++)  if(Indegree[i]==0) q.push(i);
         
        
          while(!q.empty())
             {
               int curr=q.front();
               q.pop();
            
               res+=(curr+'a');
            
              for(auto child:adj[curr])
                {
                  Indegree[child]--;
                  if(Indegree[child]==0) q.push(child);
                
                }
            }
        return res;
        
    }
};
