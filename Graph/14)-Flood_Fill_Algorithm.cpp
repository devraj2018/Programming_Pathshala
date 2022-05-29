class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       
       int oldC=image[sr][sc];
       
       if(oldC==newColor) return image;
       
       int n=image.size();
       int m=image[0].size();
        image[sr][sc]=newColor;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};
        
        while(!q.empty())
          {   int r=q.front().first;
              int c=q.front().second;
              q.pop();
           
              for(int i=0;i<4;i++)
               {
                 int new_r=r+dr[i];
                 int new_c=c+dc[i];
                 
                 if(new_r>=0 && new_c>=0 && new_r<n && new_c<m&& image[new_r][new_c]==oldC)
                 {  image[new_r][new_c]=newColor;   // Color at time of pushing to avoid taking extra visited array
                     q.push({new_r,new_c});
                 }
                
                
            }
             
            
             
           
           
       }
       return image;
       
       
    }
};