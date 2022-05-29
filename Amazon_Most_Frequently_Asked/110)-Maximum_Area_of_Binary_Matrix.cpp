====================================================================================================
----------------------------  Stack Next smaller ELement Approach O(n) + O(n^2)--------------------------
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row=matrix.size();
         int col=matrix[0].size();
        int ans=0;
        vector<int>temp(col,0);
        
        for(int i=0;i<row;i++)
        {
             for(int j=0;j<col;j++)
             {
                  if(matrix[i][j]=='1') temp[j]+=1;
                  else temp[j]=0;
                 
             }
            
          ans=max(ans,largestRectangleArea(temp));  
        }
        return ans;
        
        
    }
};