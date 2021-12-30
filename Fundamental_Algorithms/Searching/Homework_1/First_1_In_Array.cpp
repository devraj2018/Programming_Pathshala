#include <iostream>
using namespace std;
int main() {
              int n;cin>>n;
		      int arr[n];
	 	      for(int i=0;i<n;i++) cin>>arr[i];
		      int f=-1;
			  int mid,low=0,high=n-1;
			  while(low<=high)
			    {
					 mid= high -(high-low)/2;
					 if(arr[mid]==1)
					    {
							 if(mid==0)  {  f=mid;  break; }
							 else if(arr[mid-1]==1){  f=mid;  high=mid-1; }
							 else {  f=mid; break; }
					    }
					 else if(arr[mid]>1) high=mid-1;
					 else low=mid+1;
			    }

			 if(f== -1) cout<<-1<<endl;
	    	 else cout<<f+1<<endl;
			
		 
    return 0;
}