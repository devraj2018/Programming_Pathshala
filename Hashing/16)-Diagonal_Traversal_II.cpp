class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>res,temp;
        int m=mat.size();
        if(m==0) return {};
        queue<pair<int,int>>q;
        q.push({0,0});
        
        while(!q.empty())
        {
             int curr_row=q.front().first;
             int curr_col=q.front().second;
             q.pop();
            
             res.push_back(mat[curr_row][curr_col]);
            
            
             if(curr_row+1< m && curr_col==0)  // insert the element below, if in first column
                 q.push({curr_row+1,0});
             
             if(curr_col<mat[curr_row].size()-1) // insert the right neighbour, if exists
                 q.push({curr_row,curr_col+1});
        }
        
        return res;
        
    }
};