class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int up=0,left=0,right=n-1,down=n-1;
        int counter=0;
        vector<vector<int>>res(n,vector<int>(n));
        while(up<=down && left<=right)
        {
            if(left>right || up>down) break;
            for(int j=left;j<=right;j++) res[up][j]=++counter;
            up++;
            
            if(left>right || up>down) break;
            for(int i=up;i<=down;i++) res[i][right]=++counter;
            right--;
            
            
            if(left>right || up>down) break;
            for(int j=right;j>=left;j--)  res[down][j]=++counter;
            down--;
            
            if(left>right || up>down) break;
            for(int i=down;i>=up;i--) res[i][left]=++counter;
            left++;
          
        }
        return res;
        
        
    }
};