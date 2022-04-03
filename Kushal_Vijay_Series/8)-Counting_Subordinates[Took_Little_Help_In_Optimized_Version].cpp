#include<bits/stdc++.h>
using namespace std;
void dfs(int source,int par,vector<int>adj[],vector<int>&ans)
{

      int subordinate=0;

      for(auto child:adj[source])
      {
      	    if(child!=par)
            { 
                dfs(child,source,adj,ans);
                subordinate+=(1+ans[child]);
            }
      }

      ans[source]=subordinate;
 
}
int main()
{
    int n;
    cin>>n;
    vector<int>adj[n+1];
    vector<int>ans(n+1,0);
    int x;
    for(int i=2;i<=n;i++)  
     {
          cin>>x;
          adj[i].push_back(x);
          adj[x].push_back(i);

     }

       dfs(1,0,adj,ans);
       for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
} 
 
// int main()       //         n^2 Approach
// {
//    int n;
//    cin>>n;
//    vector<int>parent(n+1);
//    parent[0]=-1,parent[1]=-1;
//    for(int i=2;i<=n;i++) cin>>parent[i];
//    vector<int>cnt(n+1,0);
//    for(int i=2;i<=n;i++)
//      {   int par=parent[i];
//           while(par!=-1)
//            {
//              cnt[par]++;
//              par=parent[par];
//           }
//      }
//      for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
 
// }
     
   