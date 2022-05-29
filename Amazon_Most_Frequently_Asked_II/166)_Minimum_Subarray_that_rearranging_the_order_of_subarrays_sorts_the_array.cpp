#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int>arr={1,2,3,5,4,6,7,8};
    vector<pair<int,int>>temp;
    
    for(int i=0;i<arr.size();i++) temp.push_back({arr[i],i});
    
    sort(temp.begin(),temp.end());
    int count=0;
     int n=temp.size(),i=0;
   
     while(i<n)
        {
         	while(i+1<n && temp[i].second+1==temp[i+1].second) i++; // If already sorted in original

    	    i++;
    	    count++;
       }
     cout<<count;
     
	return 0;
}