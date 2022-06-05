/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
         
         vector<int>s,e;
         for(int i=0;i<intervals.size();i++)
         {
             s.push_back(intervals[i].start);
             e.push_back(intervals[i].end);
         }

         sort(s.begin(),s.end());
         sort(e.begin(),e.end());

         int maxx=0;
         int count=0;
         int i=0,j=0,n=s.size();

         while(i<n && j<n)
         {
              if(s[i]<e[j])
              {
                  count++;
                  i++;
              }
              else{
                  count--;
                  j++;
              }
              maxx=max(maxx,count);

         }
return maxx;
    }
};