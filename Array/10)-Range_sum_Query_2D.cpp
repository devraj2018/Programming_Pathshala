class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        // Here I took 1-1 size extra to omit 4-5 if else condition
        pre= vector<vector<int>>(row+1,vector<int>(col+1,0));  
        
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {  
               
                    pre[i][j]= pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return pre[row2+1][col2+1]-pre[row1][col2+1]-pre[row2+1][col1]+pre[row1][col1];
        
    }
};
