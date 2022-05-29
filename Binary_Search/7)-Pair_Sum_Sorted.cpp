#include <iostream>
using namespace std;
int main() {
              int n;cin>>n;
		      int arr[n];
	 	      for(int i=0;i<n;i++) cin>>arr[i];
		      int target;cin>>target; 
		       
			  int low=0,high=n-1;
			  while(low<high)
			     {
					 if(arr[low]+arr[high] == target)
						 {   cout<<low+1<<" "<<high+1<<endl;
							 	 break;
					     }
					  else if(arr[low]+arr[high] > target) high--;
					  else low++;
			    }
				

 
    return 0;
}