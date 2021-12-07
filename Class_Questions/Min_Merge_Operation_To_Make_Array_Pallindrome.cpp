#include <iostream>
using namespace std;
int min_operation(int arr[],int n)  //Minimum adjacent element merege->to_make_array_pallindrome
{    int start=0,end=n-1,ans=0;
     while(start<end)
        { 
     	    if(arr[start]==arr[end])
     	    {  
                start++,end--;continue;
     	    }
     	    if(arr[start]+arr[start+1]==arr[end])
     	     {
     	     	ans++,start+=2,end--;
     	     }
     	    else if(arr[start]==arr[end]+arr[end-1])
     	    {
     	    	ans++,start++,end-=2;
     	    }
     	    else
     	    {
     	    	start+=2,end-=2,ans+=2;
     	    }
     }
     return ans;
	
}
int main() {
   int n;cin>>n;int arr[n];
   for(int i=0;i<n;i++)  cin>>arr[i];
   
   cout<<min_operation(arr,n);
   return 0;
}