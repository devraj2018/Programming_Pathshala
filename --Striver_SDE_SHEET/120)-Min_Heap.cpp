#include<bits/stdc++.h>
vector<int> minHeap(int n, vector<vector<int>>& q) {
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>res;
    for(int i=0;i<q.size();i++)
    {
        if(q[i][0]==0) pq.push(q[i][1]);
        else{
            res.push_back(pq.top());
            pq.pop();
        }
    }
    return res;
}
