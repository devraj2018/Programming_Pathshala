struct Info{
    int x,y,dis;
    Info(int _x,int _y,int _d)
    {
        x= _x;
        y= _y;
        dis= _d;
    }
};
class Solution {
public:
    int dx[8]={-1,-1,1,1,-2,-2,2,2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
	int minStepToReachTarget(vector<int>&start, vector<int>&target, int N){
	     vector<vector<int>> vis(N+1,vector<int>(N+1,0));   
	     queue<Info>q;
	     q.push(Info(start[0],start[1],0));
	     vis[start[0]][start[1]]=1;
	     while(!q.empty())
	     { int x=q.front().x;
	        int y=q.front().y;
	          int dis=q.front().dis;
	          q.pop();
	          
	          if(x==target[0] && y==target[1])
	            return dis;
	        
	          for(int i=0;i<8;i++)
	          {  int new_x=x+dx[i];
	             int new_y=y+dy[i];
	             
	             if(new_x>=1 && new_y>=1 && new_x<=N && new_y <=N &&vis[new_x][new_y]==0)
	             {
	                q.push(Info(new_x,new_y,dis+1));
	                vis[new_x][new_y]=1;
	            }
	              
	          }
	         
	     }
	     return 0;
	     
	     
	}
};