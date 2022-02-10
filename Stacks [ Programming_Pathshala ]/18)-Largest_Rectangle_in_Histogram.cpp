class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>lse(n,-1),rse(n,n);
      
         stack<int>s;
       
         for(int i=0;i<n;i++)
         {
              while(!s.empty() && heights[s.top()]>=heights[i])
                  s.pop();
             
              if(s.empty()) lse[i]=-1;
              else lse[i]=s.top();
             
              s.push(i);
         }
         stack<int>s1;
         for(int i=n-1;i>=0;i--)
         {
              while(!s1.empty() && heights[s1.top()]>=heights[i])
                   s1.pop();
             
              if(s1.empty()) rse[i]=n;
              else rse[i]=s1.top();
             
              s1.push(i);
         }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
             ans=max(ans, heights[i]*(rse[i]-lse[i]-1));
            
            
        }
        return ans;
        
        
    }
};