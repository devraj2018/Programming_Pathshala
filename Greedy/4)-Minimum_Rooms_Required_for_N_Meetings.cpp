int Solution::solve(vector<vector<int> > &A) {
   
   map<int,int>mp;
   for(int i=0;i<A.size();i++)
         {
         int start=A[i][0];
         int end=A[i][1];
         mp[start]++;
         mp[end]--;
         }
      
       int count=0;
       int maxx=0;
       for(auto x:mp)
          {
              count+= x.second;
              maxx=max(maxx,count);
          }
       return maxx;
 }