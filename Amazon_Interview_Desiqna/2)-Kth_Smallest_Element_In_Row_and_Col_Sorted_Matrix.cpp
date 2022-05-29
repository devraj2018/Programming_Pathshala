class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
     
      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
      
      for(int i=0;i<matrix[0].size();i++)
      {
          pq.push({matrix[0][i],0,i});
      }
        
      for(int i=1;i<k;i++)
      {
          int x=pq.top()[1];
          int y=pq.top()[2];
          
          pq.pop();
          
          if(x+1<matrix.size()) pq.push({matrix[x+1][y],x+1,y});
      }
        return pq.top()[0];
        
    }
};