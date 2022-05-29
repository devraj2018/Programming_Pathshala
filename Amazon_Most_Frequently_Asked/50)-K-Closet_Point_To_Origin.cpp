class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> >pq;
        
        
        vector<vector<int>>res(k);
        for(int i=0;i<points.size();i++)
        {
            int distance= points[i][0]*points[i][0] + points[i][1]*points[i][1];
            
            if(pq.size()<k || distance< pq.top().first)
                pq.push({distance,{points[i][0],points[i][1]}});
            
            if(pq.size()>k) pq.pop();
        }
        
        for(int i=k-1;i>=0;i--)
        {
            res[i].push_back(pq.top().second.first);
            res[i].push_back(pq.top().second.second);
            pq.pop();
            
        }
        
        
        return res;
        
    }
};