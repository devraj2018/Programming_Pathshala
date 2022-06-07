#include<bits/stdc++.h>
bool comp(vector<int>&a,vector<int>&b)
{
     if(a[0]<b[0]) return true;
     if(a[0]>b[0]) return false;
     
     return a[2]<b[2];
    
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    
    vector<int>res;
    vector<vector<int>>temp;
    for(int i=0;i<start.size();i++)
    {
        temp.push_back({end[i],start[i],i});
    }
    sort(temp.begin(),temp.end(),comp);
    
     
    
    int prev_end=temp[0][0];
    res.push_back(temp[0][2]+1);
    
    for(int i=1;i<temp.size();i++)
    {
         if(temp[i][1]>prev_end)
         {
             res.push_back(temp[i][2]+1);
             prev_end=temp[i][0];
         }
    }
    
    return res;
}