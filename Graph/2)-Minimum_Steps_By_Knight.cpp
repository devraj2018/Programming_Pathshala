class Solution 
    {
    public:
	
    //Function to find out minimum steps Knight needs to reach target position.
    int dx[8]={-1,-1,1,1,-2,-2,2,2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	     queue<vector<int>>q;
	     q.push({KnightPos[0],KnightPos[1],0});
	     
	     bool visited[N+1][N+1]={false};
	     visited[KnightPos[0]][KnightPos[1]]=true;
	     
	     while(!q.empty())
	     {
	         vector<int> curr=q.front();
	         q.pop();
	         
	         int x=curr[0]; int y=curr[1]; int distance=curr[2];
	         
	         if(x==TargetPos[0] && y==TargetPos[1]) return distance;
	         
	         for(int i=0;i<8;i++)
	         {
	             int newx=x+dx[i];
	             int newy=y+dy[i];
	             
	             if(newx>=1 && newy>=1 && newx<=N && newy<=N && visited[newx][newy]==false)
	             {   q.push({newx,newy,distance+1});
	                 visited[newx][newy]=true;
	             }
	         }
	    }
	   return -1;
	 	     
	}
};