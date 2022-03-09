// Also Check BFS Approach which I did in next Question
// Very Intersting way to solve this problem
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>res,temp;
        int m=mat.size();
        int n=mat[0].size();
        int traversal=m+n-1;
        int column_helper=0;
        bool rev=false;
        for(int i=0;i<traversal;i++)
        {
             int row=min(i,m-1);
             int col; 
             if(row<m-1)
             {
                 col=0;
             }
             else
             {  col=column_helper;
                 column_helper++;
                 
             }
             
             while(row>=0 && col<n)
             {
                 temp.push_back(mat[row][col]);
                 row--;
                 col++;
             }
             
             if(rev)
                 reverse(temp.begin(),temp.end());
            
             res.insert(res.end(),temp.begin(),temp.end());
             temp.clear();
             rev = !rev;
             
        }
        return res;
        
    }
};