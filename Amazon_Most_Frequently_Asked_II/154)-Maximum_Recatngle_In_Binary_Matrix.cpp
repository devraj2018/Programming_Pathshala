class Solution {
public:
    int maxHistogram(vector<int>&arr)
    {
         int n=arr.size();
         vector<int>nse(n,n),pse(n,-1);
        
         stack<int>s1;
         for(int i=0;i<n;i++)
         {
             while(!s1.empty() && arr[s1.top()]>=arr[i])
                 s1.pop();
             
             if(!s1.empty()) pse[i]=s1.top();
             s1.push(i);
         }
         stack<int>s2;
         for(int i=n-1;i>=0;i--)
         {
             while(!s2.empty() && arr[s2.top()]>=arr[i])
                 s2.pop();
             
             if(!s2.empty()) nse[i]=s2.top();
             s2.push(i);
         }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans, (nse[i]-pse[i]-1)*arr[i]);
        }
        return ans;
        
      
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int res=0;
        vector<int>temp(col,0);
        
        for(int i=0;i<row;i++)
        {
            
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='0') temp[j]=0;
                else temp[j]+=1;
            }
            res=max(res,maxHistogram(temp));
            
        }
        return res;
    }
};