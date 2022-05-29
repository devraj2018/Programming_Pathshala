#include<bits/stdc++.h>
long long int minimumCostToConnectSticks(vector<int> &arr) {
    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
	
	long long int ans=0;
	
	while(pq.size()>1)
	{
		int a=pq.top();pq.pop();
				int b=pq.top();pq.pop();
		ans+= a+b;
		pq.push(a+b);
		
	 }
	 
	return ans;
}