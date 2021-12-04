class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>res;
        int up=0,right=matrix[0].size()-1,down=matrix.size()-1,left=0;
        
        
        while(up<=down && left<=right)
        {
              for(int j=left;j<=right;j++)
                  res.push_back(matrix[up][j]);
            
               up++;
               if(up>down || left>right)
                  continue;
            
              for(int i=up;i<=down;i++)
                  res.push_back(matrix[i][right]);
            
              right--;
              if(up>down || left>right)
                continue;
            
              for(int j=right;j>=left;j--)
                  res.push_back(matrix[down][j]);
            
              down--;
              if(up>down || left>right)
                 continue;

             for(int i=down;i>=up;i--)
                  res.push_back(matrix[i][left]);
            
             left++;
             if(up>down || left>right)
                continue;
           
        }
        return res;
        
        
    }
};