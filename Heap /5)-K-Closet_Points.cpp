struct Compare{
     bool operator()(vector<int>&a,vector<int>&b)
         {
            int x1=a[0],y1=a[1],x2=b[0],y2=b[1];
          
            int dist1= x1*x1 + y1*y1;
            int dist2= x2*x2 + y2*y2;
         
            return dist2<dist1;
         }
    
};
class Solution {
public:
     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<vector<int>,vector<vector<int>>, Compare > pq(points.begin(),points.end());
         vector<vector<int>>res;
         for(int i=0;i<k;i++)
            {

               
              res.push_back(pq.top());
              pq.pop();
             
           }
        return res;
     }
};