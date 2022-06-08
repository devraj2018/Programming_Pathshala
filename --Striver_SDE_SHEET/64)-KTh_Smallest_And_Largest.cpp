#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    int kthSmallest=n-k;
	 priority_queue<int>pq(arr.begin(),arr.end());
     int largest,smallest;
     
    for(int i=0;i<n;i++)
    {
        if(i==k-1){
            largest=pq.top();
        }
        if(i==n-k) smallest=pq.top();
        pq.pop();
    }
    return {smallest,largest};
    
}