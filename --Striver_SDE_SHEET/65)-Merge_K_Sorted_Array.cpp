#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<int>res;
    for(int i=0;i<k;i++)
    {
        pq.push({arr[i][0],{i,0}});
    }
    
    while(!pq.empty())
    {
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        res.push_back(pq.top().first);
        pq.pop();
        
        if(y+1<arr[x].size()) pq.push({arr[x][y+1],{x,y+1}});
    }
    return res;
   
}
