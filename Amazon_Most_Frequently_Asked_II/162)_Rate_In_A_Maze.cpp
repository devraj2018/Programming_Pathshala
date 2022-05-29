class Solution{
    public:
    vector<string>res;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    char dir[4]={'U','D','R','L'};
    
    void helper(int x,int y,vector<vector<int>> &matrix,int n,string &curr_path)
    {
         if(x==n-1 && y==n-1)
         {
             res.push_back(curr_path);
             return;
         }
         matrix[x][y]=0;
         
         for(int i=0;i<4;i++)
         {
              int new_x=x+dx[i];
              int new_y=y+dy[i];
              
              if(new_x>=0 && new_y>=0 && new_x<n && new_y<n&& matrix[new_x][new_y]==1)
                {    curr_path+=dir[i];
                     helper(new_x,new_y,matrix,n,curr_path);
                     curr_path.pop_back();
                }
              
          }
        matrix[x][y]=1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
     
      string curr_path="";
      if(matrix[0][0]==0 || matrix[n-1][n-1]==0) return res;
      
      helper(0,0,matrix,n,curr_path);
      sort(res.begin(),res.end());
      return res;
      
       
    }
};