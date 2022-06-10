#include<bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
	int maxp=1;
    int minp=1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0) swap(maxp,minp);
        
        maxp=max(maxp*arr[i],arr[i]);
                minp=min(minp*arr[i],arr[i]);
        
        ans=max(ans,maxp);
        
    }
    return ans;
}
