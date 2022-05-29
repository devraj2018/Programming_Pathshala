// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
		
	        int n=grid.size();int m=grid[0].size();
	    	vector<vector<int>>distance(n,vector<int>(m));
	    	queue<pair<int,int>>q;
	    	for(int i=0;i<n;i++)
	    	{    for(int j=0;j<m;j++)
	    	        {
	    	           if(grid[i][j]==1)
	    	             {
	    	              distance[i][j]=0;
	    	              q.push({i,j});
	    	             }
	    	           else distance[i][j]=INT_MAX-2;
	    	        
	    	        }
	    	}
	    	int dx[4]={-1,1,0,0};
	    	int dy[4]={0,0,-1,1};
	    	 
	    	 while(!q.empty())
	    	    {
	    	      int  x=q.front().first;
	    	      int  y=q.front().second;
	    	      q.pop();
	    	      
	    	      for(int i=0;i<4;i++)
	    	      {
	    	          int newx=x+dx[i];
	    	          int newy=y+dy[i];
	    	          
	    	          if(newx>=0 && newy>=0 && newx<n && newy<m && distance[x][y]+1 < distance[newx][newy])
	    	          {
	    	              distance[newx][newy]= distance[x][y]+1;
	    	              q.push({newx,newy});
	    	          }
	    	      }
	    	    }
	    	 return distance;
	 }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends