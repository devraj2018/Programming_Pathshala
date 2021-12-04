// Its a array containing 0 and 1 only//
// Ex--> 0 1 0 1 1 0 0 1 1//

//Its Subsequence-->>So we can remove any ele from any places//
// Our answer would be [ 2*min(count_1,count_0) ] 


#include <iostream>
using namespace std;

int main() {
  int n,zero=0,one=0;      
  cin>>n;             
  int arr[n];
  for(int i=0;i<n;i++)
   {  cin>>arr[i];
      if(arr[i]) one++;
      else zero++;
    
   }

   cout<<2*min(zero,one)<<endl;
    
}