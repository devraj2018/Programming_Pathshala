#include <iostream>
using namespace std;
int main() {
          int n;cin>>n;
		  int arr[n];
		  for(int i=0;i<n;i++) cin>>arr[i];
		
		  int t,target;cin>>t;
		  while(t--)
		    { 
				 cin>>target;
			     int ans=-1;
				 int mid,low=0,high=n-1;
			   	 while(low<=high)
				    {
						 mid= high -(high-low)/2;
						 if(arr[mid]==target)
					     	{
								ans=mid;
								break;
					    	}
						else if(arr[mid]>target)
								 high=mid-1;
						else
								 low=mid+1;
				   }
				   
				 if(ans!=-1)
				    cout<<ans<<endl;
				 else
						cout<<low<<endl;  // If not found always to be inserted at low index
				
		}
    return 0;
}