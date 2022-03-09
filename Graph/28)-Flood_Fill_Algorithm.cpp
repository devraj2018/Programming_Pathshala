class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int dx[4]={-1,1,0,0};
         int dy[4]={0,0,1,-1};
        if(image[sr][sc]==newColor) return image;
        
        int r=image.size();
        int c=image[0].size();
        
        int oldC=image[sr][sc];
        image[sr][sc]=newColor;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        while(!q.empty())
        {
             int x=q.front().first;
             int y=q.front().second;
            
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                 int newx=x+dx[i];
                 int newy=y+dy[i];
                
                 if(newx>=0 && newy>=0 && newx<r && newy<c && image[newx][newy]==oldC)
                 {
                     q.push({newx,newy});
                      image[newx][newy]=newColor;
                 }
                
                
            }
            
            
            
        }
        return image;
        
        
        
    }
};