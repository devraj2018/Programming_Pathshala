
vector<int> Solution::solve(vector<vector<int> > &A) {

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    
    int k=A.size();
    int n=A[0].size();
     
    for(int i=0;i<k;i++)
    {
         pq.push({A[i][0],{i,0}});
    }

    vector<int>res;
    while(!pq.empty())
    {
         int val=pq.top().first;
         int i=pq.top().second.first;
         int j=pq.top().second.second;

         pq.pop();
        res.push_back(val);

          if(j<n-1)
          {
              pq.push({A[i][j+1],{i,j+1}});
          }

    }
    return res;
}
