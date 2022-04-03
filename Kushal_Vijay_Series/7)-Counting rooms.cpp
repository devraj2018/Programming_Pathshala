#include<bits/stdc++.h>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y, vector<vector<char>> &matrix)
{

      matrix[x][y]='#';
      for(int i=0;i<4;i++)
      {
            int newx=x+dx[i];
            int newy=y+dy[i];

            if(newx>=0 && newy>=0 && newx<matrix.size() && newy<matrix[0].size() && matrix[newx][newy]=='.')
              dfs(newx,newy,matrix);

      }


}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<char>> matrix(n,vector<char>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
           cin>>matrix[i][j];
    }
  
   int count=0;
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
           {
                if(matrix[i][j]=='.')
                {
                    count++;
                    dfs(i,j,matrix);
                }


           }
    }
    cout<<count;




}