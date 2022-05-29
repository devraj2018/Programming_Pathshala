class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    int min_x,min_y,max_x,max_y;
    void dfs(int x,int y,vector<vector<int>>& land,int r,int c)
    {
         min_x=min(min_x,x);
         min_y=min(min_y,y);
         max_x=max(max_x,x);
         max_y=max(max_y,y);
         
         land[x][y]=0;
        
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            
            if(xx>=0 && yy>=0 && xx<r && yy<c && land[xx][yy]==1)
            {
                dfs(xx,yy,land,r,c);
            }
        }
        
        
        
        
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
     
        int r=land.size();
        int c=land[0].size();
        vector<vector<int>>res;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            { 
                 if(land[i][j]==1)
                 {
                        min_x=INT_MAX;
                        min_y=INT_MAX;
                        max_x=INT_MIN;
                        max_y=INT_MIN;
                        dfs(i,j,land,r,c);
                        res.push_back({min_x,min_y,max_x,max_y});
                     
                 }
                
            }
        }
        return res;
    }
};