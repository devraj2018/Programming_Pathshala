#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	 int xorr=0;
     for(int i=0;i<n;i++)
     {
         xorr^=arr[i];
         xorr^=(i+1);
         
     }
    int rightmostsetbit= xorr &~(xorr-1);
    
    int x=0,y=0;
    
    for(int i=0;i<n;i++)
    {  
         if(rightmostsetbit & arr[i])
         {
             x= x^arr[i];
         }
        else{
            y= y^arr[i];
        }
        
         if((i+1)&rightmostsetbit)
         {
             x= x^(i+1);
         }
        else{
            y= y^(i+1);
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x) count++;
    }
    if(count>1) return {y,x};
    return {x,y};
}
