class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        vector<vector<int>>res(row,vector<int>(col,0));
        
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                 dp[i][j]=dp[i-1][j]+dp[i][j-1]+mat[i-1][j-1]-dp[i-1][j-1];
                
                
            }
        }
        
         for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {  
                 int x1=max(0,i-k);       // Top left corner -->Calculating this way to avoid 
                 int y1=max(0,j-k);       // Out of bound condition
                 int x2=min(i+k,row-1);   //  Bottom right Corner
                 int y2=min(j+k,col-1);
               
                 res[i][j]= dp[x2+1][y2+1]- dp[x2+1][y1]-dp[x1][y2+1] + dp[x1][y1];                
                
            }
        }
        return res;
       
    }
};