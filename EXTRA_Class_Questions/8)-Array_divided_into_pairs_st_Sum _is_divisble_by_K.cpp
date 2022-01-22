//Given an array of integers and a number k, write a function that returns true if the given array can be divided into pairs such that 
//the sum of every pair is divisible by k.

#include <bits/stdc++.h>
using namespace std;
bool fun(int n,int arr[],int k)
{
	int paircount=0;
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++)
	{  if(mp.find(k-arr[i]%k)!=mp.end())
		  {
		  	paircount++;
		  	mp[k-arr[i]%k]--;
		  }
		  else
			mp[arr[i]%k]++;   //This is in else bcs if we find pair corresponding to that ele
		                     // We should not insert that ele in map 
	}
	if(paircount==n/2)
	return true;
	return false;
	
	
	
}
int main() {
 int n;
 cin>>n;int k;cin>>k;
   int arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];
    if(n&1)  // If array contain odd number of element then its not possible
    cout<<"Not formed";
    
    if(fun(n,arr,k))
    {
    	cout<<"formed";
    }
    else
    cout<<"Not formed";
    
	return 0;
}