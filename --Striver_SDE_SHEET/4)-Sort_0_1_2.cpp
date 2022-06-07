#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    int i=0,j=0,k=n-1;
    
    while(j<=k)
    {
         if(arr[j]==0)
         {
             swap(arr[i],arr[j]);
             i++;
             j++;
             

             
         }
        else if(arr[j]==2)
        {
            swap(arr[j],arr[k]);
            k--;
        }
        else j++;
        
        
        
    }
}