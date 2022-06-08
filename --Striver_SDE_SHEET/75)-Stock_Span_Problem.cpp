#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &nums) {
        stack<int>s;
        int n=nums.size();
         
        
        vector<int>res(n);
        
        for(int i=0;i<nums.size();i++)
        {
            while(!s.empty() && nums[s.top()]<=nums[i])
                s.pop();
            
            if(!s.empty()) res[i]=i-s.top();
            else res[i]=i+1;
            
            s.push(i);
            
            
        }
        return res; 
}