#include <bits/stdc++.h>
using namespace std; 



void find(int arr[],int& ans,int n)  //  If we need to find this max(Arr[i]+Arr[j]+Arr[k])
{ //We just need to take mid ele as fix and check max ele in  left side and max on right side
   
   int lmax[n];
   int rmax[n];
   lmax[0]=arr[0];rmax[n-1]=arr[n-1];
   
   for(int i=1;i<n;i++)
   {
   	 lmax[i]=max(lmax[i-1],arr[i]);
   	 rmax[n-i-1]=max(rmax[n-i],arr[n-i-1]);
   }
   
   for(int i=1;i<n-1;i++)
   {
   	ans=max(ans,lmax[i-1]+arr[i]+rmax[i+1]);
   }
}

// We need to find max value of p*Arr[i]+q*Arr[j]+r*Arr[k],and constraint  i<j<k   //

void findwithpqr(int arr[],int& ans1,int n,int p,int q,int r)  //  If we need to find this max(p*Arr[i]+q*Arr[j]+r*Arr[k])
{ //We just need to take mid ele as fix and check max ele in  left side and max on right side
   
   int lmax[n];
   int rmax[n];
   lmax[0]=p*arr[0];rmax[n-1]=r*arr[n-1];
   
   for(int i=1;i<n;i++)
   {
   	 lmax[i]=max(lmax[i-1],p*arr[i]);
   	 rmax[n-i-1]=max(rmax[n-i],r*arr[n-i-1]);
   }
   
   for(int i=1;i<n-1;i++)
   {
   	ans1=max(ans1,lmax[i-1]+q*arr[i]+rmax[i+1]);
   }
}


int main() {
    int n;
    cin>>n;
    int p,q,r;
    cin>>p>>q>>r;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    int ans=INT_MIN;
    find(arr,ans,n); // Without p q and r
    cout<<ans<<endl;
  
    int ans1=INT_MIN;
    findwithpqr(arr,ans1,n,p,q,r); 
    cout<<ans1<<endl;


}