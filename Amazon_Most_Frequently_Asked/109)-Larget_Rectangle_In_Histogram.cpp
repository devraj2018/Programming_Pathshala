====================================================================================================
----------------------------  Stack Next smaller ELement Approach O(n) -----------------------------
====================================================================================================

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int ans=0;
        int n=heights.size();
        
        vector<int>NSEL(n,-1),NSER(n,n);
        stack<int>s,s1;
        
        for(int i=0;i<n;i++)
            {     while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            
                  if(!s.empty()) NSEL[i]=s.top();
                  s.push(i);
            }
        
        for(int i=n-1;i>=0;i--)
           {
                while(!s1.empty() && heights[s1.top()]>=heights[i]) s1.pop();
            
                if(!s1.empty()) NSER[i]=s1.top();
                s1.push(i);
           }
         for(int i=0;i<n;i++)
           {
              ans=max(ans, heights[i]*(NSER[i]-NSEL[i]-1));
           }
        return ans;
        
    }
};

====================================================================================================
----------------------------   Brute Force  O(n^2) -------------------------------------------------
====================================================================================================

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int ans=0;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            int left=i-1,right=i+1;
            
            while(left>=0 && heights[left]>=heights[i])
            {
                left--;
            }
            while(right<n && heights[right]>=heights[i])
            {
                right++;
            }
            
            ans=max(ans,heights[i]*(right-left-1));
            
        }
        return ans;
    }
};