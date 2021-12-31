#include <iostream>
using namespace std;
int main() {         // Logn Approach
      int n;cin>>n;
		  int arr[n];
	 	  for(int i=0;i<n;i++) cin>>arr[i];
		  int ans;
		  int mid,low=0,high=n-1;
			     while(low<=high)
			    	{
					   	mid= high -(high-low)/2;
							
							 int prev=max(0,mid-1);
							 int next=min(n-1,mid+1);
					    
							 if(arr[mid]==arr[prev])
							 {
									  if(mid&1) low=mid+1;
									  else high=mid-1;
						     }
							 else if(arr[mid]==arr[next])
							 {
									  if(mid&1) high=mid-1;
									  else low=mid+1;
						     }
							 else
									  break;
							 
							 
							 
			      	}
         cout<<arr[mid]<<endl;
    return 0;
   }