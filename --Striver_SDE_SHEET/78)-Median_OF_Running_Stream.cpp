#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int>maxx;
    priority_queue<int,vector<int>,greater<int>>minn;
    for(int i=0;i<n;i++)
    {    int num=arr[i];
         if(maxx.empty() ||num<= maxx.top())
            maxx.push(num);
         else
            minn.push(num);
        
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
        
          if(maxx.size()==minn.size()) cout<<(maxx.top()+minn.top())/2;
          else cout<<(maxx.size()>minn.size()?maxx.top():minn.top());
         cout<<" ";
        
        
    }
     
}