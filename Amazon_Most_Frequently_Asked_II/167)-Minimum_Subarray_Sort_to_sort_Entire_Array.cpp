=====You are given an integer array ‘ARR’. You have to find the length of the ===========
=====shortest contiguous subarray such that, if you sort this subarray in ===============
=====ascending order, then the whole array will be sorted in ascending order.============

#include<bits/stdc++.h>
int subarraySort(vector< int > &arr) {
    int n=arr.size();
	
	vector<pair<int,int>>temp;
	for(int i=0;i<n;i++) temp.push_back({arr[i],i});
	sort(temp.begin(),temp.end());
	int first=-1,last=-1;
	for(int i=0;i<n;i++)
	{
		if(temp[i].second!= i && first==-1) first=i;
		
		if(temp[i].second!= i) last=i;
	}
	if(first==-1) return 0;    //If already Sorted
	return last-first+1;
	
}