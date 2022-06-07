#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
  
    long ans=0;
    int i=0,j=n-1;
    long lmax=0,rmax=0;
    
    while(i<=j)
    {
        lmax=max(lmax,arr[i]);
                rmax=max(rmax,arr[j]);
        
        if(lmax<=rmax)
        {
            ans+= lmax-arr[i];
            i++;
        }
        else{ ans+= rmax-arr[j];
            j--;
        }
    }
    return ans;
}