#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n=3,m=4;
    int mat[n][m] = { { 1, 0, 1, 2 },
                      { 0, 2, 4, 1 },
                      { 1, 2, 1, 0 } 
                    };
 
 
 
    vector<vector<int>>q = {{ 0, 0, 1, 1, 2 },
                 { 0, 2, 3, 4, 6 },
                 { 2, 2, 3, 3, 8 },
                 { 2, 1, 3, 1, 6 }
                  };
 
    vector<vector<int>>res(n,vector<int>(m,0));
 
 
    for(int i=0;i<q.size();i++)
    {
    	int from_x=q[i][0];
    	int from_y=q[i][1];
    	int to_x=q[i][2];
    	int to_y=q[i][3];
    	int k=q[i][4];
 
 
    	res[from_x][from_y]+=k;
 
    	if(to_x+1<n) res[to_x+1][from_y]-=k;
    	if(to_y+1<m) res[from_x][to_y+1]-=k;
    	if(to_x+1<n && to_y+1<m) res[to_x+1][to_y+1]+=k;
 
 
    }
 
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		 if(i==0 && j==0) continue;
    		 if(i==0) res[i][j]+=res[i][j-1];
    		 else if(j==0) res[i][j]+=res[i-1][j];
    		 else res[i][j]+= res[i][j-1]+res[i-1][j]-res[i-1][j-1];
 
    	}
    }
 
     for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	  cout<<res[i][j]<<" ";
    	 cout<<endl; 
    }
	return 0;
}