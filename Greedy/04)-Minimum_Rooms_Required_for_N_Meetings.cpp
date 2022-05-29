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

 ------------------------------------------------------------------------------------------
 ------------------------------      Nlogn Method  ---------------------------------------- 
 ------------------------------------------------------------------------------------------

 int Solution::solve(vector<vector<int> > &intervals) {
    vector<int> start;
    vector<int> end;
    for (int i = 0; i < intervals.size(); i++)
    {
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int i = 1, j = 0, curr = 1;
    int answer = 1;
    while (i < start.size() && j < end.size())
    {
        if (start[i] < end[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        answer = max(answer, curr);
    }
    return answer;
}
