#include <bits/stdc++.h>
using namespace std;

int main() {
      int n;
      cin>>n;
      vector<int>arr(n);
      for(int i=0;i<n;i++)
         cin>>arr[i];
      stack<int>s;
      vector<int>res(n,-1);
    
      s.push(arr[n-1]);
       for(int i=n-2;i>=0;i--)
        {
    	   while(!s.empty() && s.top()<=arr[i])
    	      s.pop();
    	   if(!s.empty())
    	      res[i]=s.top();
    	   
    	   s.push(arr[i]);
       }
     for(int i=0;i<n;i++)
       cout<<res[i]<<" ";
    
    
	return 0;
}