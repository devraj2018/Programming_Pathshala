//Given an integer array A, efficiently 
//find a sorted triplet such that A[i] < A[j] < A[k] 
//and 0 <= i < j < k < n, where n is the array size.
#include <iostream>
using namespace std;

int main() {
  int n;
  cin>>n;                              // O(n)Time  && O(1)Space
  int arr[n];                         
  for(int i=0;i<n;i++)
  cin>>arr[i];
  int suffmax[n];
  suffmax[n-1]=arr[n-1];
   for(int i=n-2;i>=0;i--)
    suffmax[i]=max(suffmax[i+1],arr[i]);
  int currmin=arr[0];
  bool flag=false;
  for(int i=1;i<n-1;i++)
    {  
          if(currmin<arr[i] && arr[i]<suffmax[i+1])
            {
            	flag=true;
            	break;
            }
   	
    }
    if(flag)
    cout<<"Possible";
    else
    cout<<"Not Possible";
}