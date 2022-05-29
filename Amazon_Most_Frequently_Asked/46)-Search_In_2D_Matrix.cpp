class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        
        
        int i=0,j=row*col-1;
        int mid;
        while(i<=j)
        {
             mid= (i+j)/2;
             if(matrix[mid/col][mid%col]==target) return true;
             if(matrix[mid/col][mid%col]>target) j=mid-1;
             else i=mid+1;
         }
        return false;
        
    }
};