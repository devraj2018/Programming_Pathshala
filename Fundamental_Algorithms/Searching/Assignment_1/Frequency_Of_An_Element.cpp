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
			     int f=-1;
				 int mid,low=0,high=n-1;
			     while(low<=high)
			    	{
					  	mid= high -(high-low)/2;
					   	if(arr[mid]==target)
					   	     {
								  if(mid==0)
								      {  f=mid;  break;
								      }
								   else{ f=mid;  high=mid-1;
							        	}
					     	}
						else if(arr[mid]>target) high=mid-1;
						else low=mid+1;
			    	}

				int s=-1;
				low=0,high=n-1;
			  	while(low<=high)
			    	 {
					  	 mid= high -(high-low)/2;
					     if(arr[mid]==target)
					     	{
								 if(mid==n-1)
								   {    s=mid; break;
								   }
								else{   s=mid; low=mid+1;
							    	}
						   }
						else if(arr[mid]>target) high=mid-1;
						else low=mid+1;
			     	}
			 
			    if(f== -1) cout<<0<<endl;
				else cout<<s-f+1<<endl;
				
		 }
    return 0;
}