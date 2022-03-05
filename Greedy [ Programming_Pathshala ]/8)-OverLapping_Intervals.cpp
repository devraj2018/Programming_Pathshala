bool comp( vector<int>&a, vector<int>&b)  return a[1]<b[1];
          
class Solution {
   public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
     
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        int  count=-1;
        
        int end=intervals[0][1];
        for(int i=0;i<n;i++)
            {
               if(intervals[i][0]<end)  count++;
               else end=intervals[i][1];
            }
        return  count;
    }
};