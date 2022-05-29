class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {   int R=matrix.size();
        int C=matrix[0].size();
        unordered_set<int>row,col;   // We can also use Simple two array here
    
        for(int i=0;i<R;i++)
          {
             for(int j=0;j<C;j++)
               { 
                  if(matrix[i][j]==1)
                    {
                      row.insert(i);
                     col.insert(j);
                    }
                }
           }
       for(int i=0;i<R;i++)
         {
           for(int j=0;j<C;j++)
               { 
                  if(matrix[i][j]==0 && (row.find(i)!=row.end()  ||col.find(j)!=col.end()))
                    {
                      matrix[i][j]=1;
                    }
              }
          }
    
    
    }
};