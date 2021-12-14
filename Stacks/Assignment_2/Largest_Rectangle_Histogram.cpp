class Solution {  // This solution uses O(n)Space and time complexity is also O(n) 
public:
    void Left_Smaller_Ele(vector<int>& heights,vector<int>&LSI,int n)
    {
        stack<pair<int,int>>s;
        s.push({heights[0],0});
        for(int i=1;i<n;i++)
        {  
             while(!s.empty() && s.top().first>= heights[i])
                 s.pop();
            if(!s.empty())
            {
                LSI[i]=s.top().second;
            }
            s.push({heights[i],i});
       }
    }
    void Next_Smaller_Ele(vector<int>& heights,vector<int>&RSI,int n)
    {
        stack<pair<int,int>>s;
         s.push({heights[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {  
             while(!s.empty() && s.top().first>= heights[i])
                 s.pop();
            if(!s.empty())
            {
                RSI[i]=s.top().second;
            }
            s.push({heights[i],i});
       }
    }


    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>LSI(n,-1);            // Storing next smaller ele index on left side
        vector<int>NSI(n,n);           // Storing next smaller ele index on right side 
        Left_Smaller_Ele(heights, LSI, n);
        Next_Smaller_Ele(heights, NSI, n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans, heights[i]*(NSI[i]-LSI[i]-1));
        }
       
        return ans;
        
    }
};