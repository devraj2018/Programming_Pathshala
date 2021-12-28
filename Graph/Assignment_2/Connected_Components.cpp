#include<bits/stdc++.h>
using namespace std;
void dfs(int src, vector<int>adj[],vector<bool>&vis)
  {
     vis[src]=true;
      for(auto x:adj[src])
        { 
           if(!vis[x]) dfs(x,adj,vis);
       }
}
int main()
{ 
     int n,e,u,v;cin>>n>>e;
     vector<int>adj[n+1];
     for(int i=0;i<e;i++)
       {
           cin>>u>>v;
           adj[u].push_back(v);
           adj[v].push_back(u);
       }

       vector<bool>vis(n+1,false);
       int count=0;
       for(int i=1;i<=n;i++)
       {
            if(!vis[i])
            {   count++;
                dfs(i,adj,vis);
            }

       }
       cout<<count<<endl;
 
}