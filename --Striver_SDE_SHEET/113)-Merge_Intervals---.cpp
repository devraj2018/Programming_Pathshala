#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(),intervals.end());
    
    vector<vector<int>> res;
    int i=0;
    int n=intervals.size();
    
    while(i<n)
    {
        int start=intervals[i][0];
        int end=intervals[i][1];
        
        while(i<n &&intervals[i][0] <= end)
        {
            start=min(start,intervals[i][0]);
            end=max(end,intervals[i][1]);
            i++;
        }
        res.push_back({start,end});
        
        
    }
    return res;
    
}
