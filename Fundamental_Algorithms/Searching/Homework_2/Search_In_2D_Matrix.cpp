#include <iostream>
using namespace std;
int main() {
     int m,n;cin>>m>>n;
		  int arr[m][n];
		  for(int i=0;i<m;i++)
			{
					for(int j=0;j<n;j++)
							cin>>arr[i][j];
			}
		int t,target;cin>>t;
		while(t--)
		{ cin>>target;
		 
		  int mid,low=0,high=m*n-1;
		  bool ans=false;
		  while(low<=high)
			{
					mid= high -(high-low)/2;
					if(arr[mid/n][mid%n]==target)
					{
							ans=true;
							break;
					}
					else if(arr[mid/n][mid%n]>target)
							high=mid-1;
					else
							low=mid+1;
							
					
			}
		 if(ans)
				 cout<<"true"<<endl;
		 else
				 cout<<"false"<<endl;
				
				
				
		}
		
		
    return 0;
}