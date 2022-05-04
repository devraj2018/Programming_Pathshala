int Solution::solve(vector<vector<int> > &A) {
     
     map<int,int>mp;

     for(int i=0;i<A.size();i++)
     {
         mp[A[i][0]]++;
         mp[A[i][1]]--;
     }
     int maxx=0;
     int curr_room=0;
     for(auto x:mp)
       {
         curr_room+=x.second;
         maxx=max(maxx,curr_room);
       }
     return maxx;


    
}
