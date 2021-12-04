#include <bits/stdc++.h>
using namespace std; 

long long findwithpqr(long long arr[],long long n,long long p,long long q,long long r)  
{ 
   long long ans1=LLONG_MIN;
   long long lmax[n];
   long long rmax[n];
   lmax[0]=p*arr[0];rmax[n-1]=r*arr[n-1];
   
   for(long long i=1;i<n;i++)
   {
   	 lmax[i]=max(lmax[i-1],p*arr[i]);
   	 rmax[n-i-1]=max(rmax[n-i],r*arr[n-i-1]);
   }
   
   for(long long i=0;i<n;i++)
   {
   	ans1=max(ans1,lmax[i]+q*arr[i]+rmax[i]);
   }
   return ans1;

}


int main() {
    long long n,p,q,r;
    cin>>n;
    
    cin>>p>>q>>r;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    long long ans=findwithpqr(arr,n,p,q,r); 
    cout<<ans<<endl;


}