
//          Wrong Answer need to do it again//
#include<bits/stdc++.h>
using namespcae std;

int main()
{
  int n;cin>>n;int t;cin>>t;
  int ans=0;
  int gap=1;
  
  int total_glass= n*(n+1)/2;
  bool flag=true;
  while(curr<=t)
  {  
     
     curr+=gap;
     
     gap++;
    
  }
  ans=gap*(gap-1)/2;
  if(total_glass<=ans)
   cout<<total_glass<<endl;
  else
   cout<<ans<<endl;


}