#include <iostream>
using namespace std;
int main() {
          int n;cin>>n;
		      int A[n],B[n];
		      int i,ans;
		      for(i=0;i<n;i++) cin>>A[i];
		      for(i=0;i<n-1;i++) cin>>B[i];
		      
		      int mid,low=0,high=n-1;
				  while(low<=high)
				     {
						    mid= high -(high-low)/2;
					    	if(A[mid]!= B[mid])
						      {
							      high=mid-1;
					         }
						     else
							    	low=mid+1;
				   }
				  cout<<low<<endl;
				
		  
    return 0;
}