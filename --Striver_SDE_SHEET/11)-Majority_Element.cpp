#include <bits/stdc++.h> 
int findMajorityElement(int nums[], int n) {
	    int majele=0;
        int majcount=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==majele)
            {
                majcount++;
                
            }
            else if(majcount==0)
            {
                majcount=1;
                majele=nums[i];
            }
            else
                majcount--;
        }
    
     int count=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==majele) count++;
    }
        if(count>n/2)
        return majele;
    return -1;
}