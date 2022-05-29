#include <bits/stdc++.h>
using namespace std;
vector<int>prime;
vector<bool>arr(1000001,true);
void sieve()
{
	 arr[0]=false;
	 arr[1]=false;
	 for(int i=2;i*i<=1000000;i++)
	 {
	 	if(arr[i])
	 	   {
	 	    	for(int j=2*i;j<=1000000;j+=i)
	 	     	{
	 	  		arr[j]=false;
	 	     	}
	 	  }
	 }
	  for(int i=2;i<=1000000;i++)
	  {
	  	if(arr[i])
	  	prime.push_back(i);
	  }
	
	
}
void dfs(int src, vector<int>adj[],vector<bool>&vis,int &count)
  {
      vis[src]=true;
      count++;
      for(auto x:adj[src])
        { 
           if(!vis[x]) dfs(x,adj,vis,count);
        }
}
int main() {
	sieve();
	int t;cin>>t;while(t--)
	{
	 int n,e,u,v;cin>>n>>e;
	 
     vector<int>adj[n+1];
     for(int i=0;i<e;i++)
       {
           cin>>u>>v;
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
     if(e==0)
	 {
	 	cout<<-1<<endl;
	 	continue;
	 }
       vector<bool>vis(n+1,false);
       int maxx=0;
      
       for(int i=1;i<=n;i++)
       {
            if(!vis[i])
            {   int count=0;
                dfs(i,adj,vis,count);
                maxx=max(maxx,count);
            }

       }
       cout<<prime[maxx-1]<<endl;
	}
	return 0;
}