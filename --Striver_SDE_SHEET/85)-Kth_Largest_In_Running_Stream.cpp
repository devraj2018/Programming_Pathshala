#include<bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    Kthlargest(int kk, vector<int> &arr) {
        k=kk;
        for(int i=0;i<arr.size();i++)
        {
            if(pq.size()<k || pq.top()<arr[i])
                pq.push(arr[i]);
            
            if(pq.size()>k) pq.pop();
        }
    }

    void add(int num) {
        if(pq.size()<k || pq.top()<num)
                pq.push(num);
            
            if(pq.size()>k) pq.pop();
    }

    int getKthLargest() {
      return pq.top();
    }

};