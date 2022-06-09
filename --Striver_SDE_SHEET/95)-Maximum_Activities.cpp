#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
     vector<pair<int,int>>temp;
     for(int i=0;i<start.size();i++)
     {
         temp.push_back({finish[i],start[i]});
     }
    sort(temp.begin(),temp.end());
    int count=1;
    int prev_end=temp[0].first;
    
    for(int i=1;i<temp.size();i++)
    {
        if(temp[i].second>=prev_end)
        {
            count++;
            prev_end=temp[i].first;
        }
    }
    return count;
}