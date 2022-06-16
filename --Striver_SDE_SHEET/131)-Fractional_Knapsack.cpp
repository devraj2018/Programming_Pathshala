#include<bits/stdc++.h>
bool comp(pair<int, int>&a,pair<int, int>&b)
{
    return a.second*b.first>a.first*b.second;
    
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    double ans=0.0;
    sort(items.begin(),items.end(),comp);
    for(int i=0;i<items.size();i++)
    {
        if(w>=items[i].first)
        {
            ans+=items[i].second;
            w-=items[i].first;
        } 
        else{
         ans+= w*(1.0*items[i].second/items[i].first) ;
            break;
            
            
        }
        
        
    }
    return ans;
}