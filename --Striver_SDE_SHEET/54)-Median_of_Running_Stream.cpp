#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
      priority_queue<int>maxx;
      priority_queue<int,vector<int>,greater<int>>minn;
      vector<int>res;
    
    
     for(int i=0;i<n;i++)
     {
          if(maxx.empty() ||arr[i]<= maxx.top())
            maxx.push(arr[i]);
        else
            minn.push(arr[i]);
        
        if(maxx.size()>1+minn.size())
        {
            minn.push(maxx.top());
            maxx.pop();
        }
        if(minn.size()>1+maxx.size())
        {
            maxx.push(minn.top());
            minn.pop();
        }
         
          if(maxx.size()==minn.size()) res.push_back((maxx.top()+minn.top())/2);
         else{
         int ans=maxx.size()>minn.size()?maxx.top():minn.top();
             res.push_back(ans);
         }
         
         
     }
    return res;
	 
}
