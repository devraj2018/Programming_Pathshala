#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &nums, int n) {
     stack<int>s;
 
        
        
        vector<int>res(n,-1);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            
            if(!s.empty()) res[i]=s.top();
            
            s.push(nums[i]);
            
            
        }
        return res;

}