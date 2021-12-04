class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        for(int i=0;i<row;i++)   // Calculate Transpose of matrix
          {  for(int j=i;j<row;j++)
               {  int temp=matrix[i][j];
                  matrix[i][j]=matrix[j][i];
                  matrix[j][i]=temp;
               }
          }
         for(int i=0;i<row;i++)               //Then reverse every row ,You will get your rotated image
             reverse(matrix[i].begin(),matrix[i].end());
        
    }
};