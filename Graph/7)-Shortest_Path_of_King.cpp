#include<bits/stdc++.h>
using namespace std;
struct Info{
    int x,y,dis;
    vector<string> s;
    Info(int _x,int _y,int _d, vector<string> ss)
    {
        x= _x;
        y=_y;
        dis=_d;
        s=ss;
    }
};
int main()
{    
      string start,end;
      cin>>start>>end;
      int start_x= start[0]-'a';
      int start_y= start[1]-'1';
      int end_x= end[0]-'a';
      int end_y= end[1]-'1';
     // cout<<start_x<<" "<<start_y<<" "<<end_x<<" "<<end_y<<endl;
      swap(start_x,end_x);
      swap(start_y,end_y);
      vector<vector<bool>> vis(8,vector<bool>(8,false));
      int ans;
      vector<string> path;
      int dx[8]={-1,-1,-1,0,0,1,1,1};
      int dy[8]={-1,0,1,-1,1,-1,0,1};
      string array[8]={"RU","R","RD","U","D","LU","L","LD"};
      queue<Info>q;
      q.push(Info(start_x,start_y,0,{}));
      vis[start_x][start_y]=true;
      while(!q.empty())
      {
            int x=q.front().x;
            int y=q.front().y;
            int dis=q.front().dis;
           
             vector<string> curr=q.front().s;
              q.pop();

            if(x == end_x && y==end_y)
              {
                ans=dis;
                path=curr;
                break;
              }
          
            for(int i=0;i<8;i++)
            {  int new_x=x+dx[i];
                int new_y=y+dy[i];

                 if(new_x>=0 && new_y>=0 && new_x<8 && new_y<8 && vis[new_x][new_y]==false)
                 {
                      vis[new_x][new_y]=true;
                      vector<string>temp=curr;
                      temp.push_back(array[i]);
                      q.push(Info(new_x,new_y,dis+1,temp));
                 }
            }
 
      }
      cout<<ans<<endl;
     for(auto x:path)
     {
         cout<<x<<endl;
     }


}