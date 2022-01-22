#include <iostream>
using namespace std;
int main() {
      int n;cin>>n;
		  int arr[n];
	 	  for(int i=0;i<n;i++) cin>>arr[i];
		
		   int mid,low=0,high=n-1;
			     while(low<=high)
			    	{
					   	mid= high -(high-low)/2;
					    if(arr[mid]==mid+1) low=mid+1;
						   else high=mid-1;
			    	}
    cout<<arr[low]<<endl;
    return 0;
}