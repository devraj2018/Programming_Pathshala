#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int k)
{
	priority_queue<int>pq(arr.begin(),arr.end());
    int ans;
    while(k--)
    {
        ans=pq.top();
        pq.pop();
    }
    return ans;
}