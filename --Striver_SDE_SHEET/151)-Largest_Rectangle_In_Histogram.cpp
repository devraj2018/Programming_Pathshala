#include<bits/stdc++.h> 
int largestRectangle(vector < int > & heights) {
    int n=heights.size();
        vector<int>lse(n,-1),rse(n,n);
        
        stack<int>s1;
        for(int i=0;i<n;i++)
        {
            while(!s1.empty() && heights[s1.top()]>=heights[i]) s1.pop();
            
            if(!s1.empty()) lse[i]=s1.top();
            s1.push(i);
            
        }
        stack<int>s2;
        for(int i=n-1;i>=0;i--)
        {
            while(!s2.empty() && heights[s2.top()]>=heights[i]) s2.pop();
            
            if(!s2.empty()) rse[i]=s2.top();
            s2.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans, heights[i]*(rse[i]-lse[i]-1));
        }
        return ans;
        
 }