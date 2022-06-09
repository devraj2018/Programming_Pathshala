#include <bits/stdc++.h> 

long long helper(long long x,long long n,long long m)
{
    
      if(n==1) return x%m;
      long long temp=helper(x,n/2,m)%m;
      if(n%2==0)  return temp*temp%m;
      return temp%m*helper(x,n/2+1,m)%m;
     
}
int modularExponentiation(int x, int n, int m) {
	
        long long mm= (long long)m;
        long long nn= (long long)n;
        long long xx= (long long)x;
        long long ans=helper(xx,nn,mm);
     
       return (int)ans;
    
}