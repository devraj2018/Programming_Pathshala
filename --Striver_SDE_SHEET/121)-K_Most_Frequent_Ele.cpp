#include<bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
     unordered_map<int,int>mp;
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     for(int i=0;i<n;i++) mp[arr[i]]++;
    
     for(auto m:mp){
        
        pq.push({m.second,m.first});
         if(pq.size()>k) pq.pop();
       }
    vector<int>res;
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(),res.end());
    return res;
    
}