#include <iostream>
using namespace std;
bool isArm(int n)
{
	int sum=0,r,temp; temp=n;    
    while(n>0)    
     {    
      r=n%10;    
      sum=sum+(r*r*r);    
      n=n/10;    
     }    
   if(temp==sum) return true;   
   return false;  

}
int main() {

   int n;cin>>n;
   int arr[n];
   for(int i=0;i<n;i++) cin>>arr[i];
   int i=0,s=0,e=n-1;
   while(i<=e)
   {    if(isArm(arr[i]))
          swap(arr[i],arr[e--]);
   	     else if((arr[i]&1)==0)
          swap(arr[i++],arr[s++]);
         else
          i++;
   	
   }
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";
   
	return 0;
}