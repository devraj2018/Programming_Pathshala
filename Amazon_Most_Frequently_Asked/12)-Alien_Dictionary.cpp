class Solution{
    void dfs(int src,vector<int>adj[],vector<bool>&vis,string &ans)
    {
          vis[src]=true;
         
          for(auto x:adj[src])
          {
               if(!vis[x])
                dfs(x,adj,vis,ans);
              
          }
      char val= 'a'+src;  
      ans+= val;
         
    }
    public:
    string findOrder(string words[], int N, int K) {
       
       
        vector<int>adj[K];
        if(N==1) return words[0];
       
        for(int i=1;i<N;i++)
       {
          string first=words[i-1];
          string second=words[i];
          int minn=min(first.length(),second.length());
          for(int j=0;j<minn;j++)
          {
              if(first[j]!=second[j])
               {
                   adj[first[j]-'a'].push_back(second[j]-'a');
                   break;
               }
          }
       }
       
       
       vector<bool>vis(K,false);
       string ans="";
       for(int i=0;i<K;i++)
       {
           if(!vis[i])
             dfs(i,adj,vis,ans);
       }
      
       reverse(ans.begin(),ans.end());
       return ans;

       
       
       
    }
};