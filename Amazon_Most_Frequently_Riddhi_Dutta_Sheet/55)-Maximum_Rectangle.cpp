class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix[0].size();
        vector<int>temp(n,0);
        int ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1') temp[j]++;
                else temp[j]=0;
            }
            ans=max(ans,largestRectangleArea(temp));
        }
        return ans;
    }
};