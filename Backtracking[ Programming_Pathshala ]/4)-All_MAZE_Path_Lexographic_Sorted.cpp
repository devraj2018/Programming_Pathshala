#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char D[4]={'U','R','D','L'};


void dfs( vector<vector<int>>&grid,string &curr_path, vector<string>&all_path,int x,int y )
{
      if(grid[x][y]==0) return;
      if(x== grid.size()-1 && y==grid.size()-1 )
      {   all_path.push_back(curr_path);
           return;
      }
      grid[x][y]=0;
    
      for(int i=0;i<4;i++)
      {
          int newx=x+dx[i];
          int newy=y+dy[i];
          
           if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid.size() && grid[newx][newy]==1)
            {   curr_path.push_back(D[i]);
                dfs(grid,curr_path,all_path,newx,newy);
                curr_path.pop_back();
            }
      }
       grid[x][y]=1;
      
}


int main() {
	
	  int t;cin>>t;while(t--)
	  {    int num;cin>>num;
	       vector<vector<int>> grid(num,vector<int>(num,0));
	       for(int i=0;i<num;i++)
	       {
	           for(int j=0;j<num;j++)
	             {
                     cin>>grid[i][j];
                 }
	       }
	      
	       vector<string>all_path;
	       string curr_path="";
	       
	       dfs(grid,curr_path,all_path,0,0);
	       sort(all_path.begin(),all_path.end());   //To print Lexographically 
	      
	        for(auto x:all_path)
	          {   cout<<x<<" ";
	          }
	       cout<<endl;
	  	  }
	  
	return 0;
}
