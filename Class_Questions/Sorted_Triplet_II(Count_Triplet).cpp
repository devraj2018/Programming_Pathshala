//Given an integer array A, efficiently 
//find total no of sorted triplet such that A[i] < A[j] < A[k] 
//and 0 <= i < j < k < n, where n is the array size.
#include <iostream>
using namespace std;

int main() {
  int n,ans=0;        // We can do it in nlogn with Advanced data Structures But no need at this level
  cin>>n;                       // O(n^2)Time-Best Possible  and O(1)space   
  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];
   int leftmin_count=0,rightmax_count=0;
    for(int i=1;i<n-1;i++)
    {
         for(int j=0;j<i;j++)
            if(arr[j]<arr[i]) leftmin_count++;
         
         for(int j=i+1;j<n;j++)
            if(arr[i]<arr[j]) rightmax_count++;

         ans + = leftmin_count*rightmax_count;
   
    }

    cout<<ans<<endl;
   


    
}