#include <bits/stdc++.h>
using namespace std;

int main() {
     int n,k;
     cin>>n>>k;
     vector<int>arr1(n),arr2(k);
      unordered_set<int>s;
      for(int i=0;i<n;i++)
       {
    	cin>>arr1[i];
    	s.insert(arr1[i]);
      }
      vector<int>res;
      for(int i=0;i<k;i++)
        {
    	  cin>>arr2[i];
    	 if(s.find(arr2[i])!=s.end())
    	  res.push_back(arr2[i]);
    	  
        }
    
    for(auto x:res)
    cout<<x<<" ";
    
    
	return 0;
}