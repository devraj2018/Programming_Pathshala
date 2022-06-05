class Solution {
    struct comp{
        bool operator()(vector<int>&a,vector<int>&b)
        {
           return a[2]<=b[2];
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>,vector<vector<int>>,comp>pq; // max heap
        
        for(int i=0;i<points.size();i++)
        {
             int d= points[i][0]*points[i][0]+ points[i][1]*points[i][1];
             if(pq.size()<k || pq.top()[2]>d )
             {
                 pq.push({points[i][0],points[i][1],d});
             }
             if(pq.size()>k) pq.pop();
            
        }
        
        vector<vector<int>>res(k);
        
        for(int i=k-1;i>=0;i--)
        {
            res[i]={pq.top()[0],pq.top()[1]};
            pq.pop();
            
        }
        return res;
    }
};