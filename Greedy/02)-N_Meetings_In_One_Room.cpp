class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
           vector<pair<int,int>>box;
           
           for(int i=0;i<n;i++) box.push_back({end[i],start[i]});
           sort(box.begin(),box.end());
           
           int count=1;
           int prev_end=box[0].first;
           
           for(int i=1;i<n;i++)
              {
                  if(prev_end<box[i].second)
                     {
                       count++;
                       prev_end=box[i].first;
                     }
              }
              
           return count;
     }
};