#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
   vector<int>arr(n+1,0);
   
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    
     int newi=0;
     int prev=k;
     bool vis[n+1]={false};
     vis[k]=true;
     bool flag=true;
     while(newi!=k)
     {
     	 
     	 newi= (prev+arr[prev])%n+1;
     	 cout<<prev<<"-->>"<<newi<<endl;  // Printing cycle to debug only
     	 if(vis[newi]==true && newi==k)
     	  {
     	  	flag=true;
     	  	break;
     	  }
     	  if(vis[newi])
     	  {
     	  	flag=false;
     	  	break;
     	  }
     	  vis[newi]=true;
     	  prev=newi;
     }
     if(flag)
     cout<<"Cycle";
     else cout<<"No Cycle";
    
	return 0;
}