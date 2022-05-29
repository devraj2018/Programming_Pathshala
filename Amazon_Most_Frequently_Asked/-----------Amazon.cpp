Q1: You are given a list of integers. You need to perform an operation on this array which will remove 
    2 max elements and add the difference back to the list. Find the last element which will remain.

Example:
[5,6,15,12] => [5,6,3] => [1,3] => [2]
ans = 2

*/

 int helper(vector<int>&arr) // Time-> nlogn and O(n) Space
 {
     // Time-> nlogn and O(n) Space
      priority_queue<int,vector<int>> pq(arr.begin(),arr.end());
      
      while(pq.size()>1)
      {
          int x=pq.top();   // O(1) Time
          pq.pop();          // log n Time
          int y=pq.top();
          pq.pop();
          
          pq.push(x-y);     // log(n)
     }
     
     int ans=pq.top();
     return ans;
  }

                   [1,2,3,4,5,6,7,8,9,10]
                        7
                     5     6
                   4   2  1  3  
                   
                   
                   
                   
        10
     8     9
   5   6  7  4
   
   
       size--
       

/**

Q2: You are given a n×m size grid. Some of the cells of the grid are blocked. There are two robots one standing 
    at (1, 1) and other at (n, m). In a single move, a robot can move from a cell (i, j) to cell (x, y) 
    such that |x - i| + |y - j| ≤ S Both the robots make moves simultaneously, find out minimum number of moves 
    required so that both the robots meet at some common cell. If it is not possible for them to meet, print -1 

Sample Case: n=4, m=5
X 1 0 1 0
0 0 1 0 1
1 0 0 1 0
0 1 0 0 Y
Answer = 4

*/
  
     int calculate(vector<vector<int>>&arr,vector<vector<int>>&dp,int startx,int starty)
     {
          int row=arr.size();               
          int col=arr[0].size();
         int dx[4]={-1,1,0,0};
         int dy[4]={0,0,-1,1};
         queue<pair<int,int>>q;
         q.push({startx,starty});
         dp[startx][starty]=0;
         
         while(!q.empty())        // n*m*s*s
         {
              int x=q.front().first;
              int y=q.front().second;
              q.pop();
              
              // If |x - i| + |y - j| ≤ S
              
              
              for(int i=-S;i<=S;i++)
              {
                  for(int j=-S;j<=S;j++)
                  {
                       if(abs(x-i) + abs(y-j) <=S)
                       {
                           int newx=i,newy=j;
                       }
                      
                  }
              }
              
              
              // If |x - i| + |y - j| ≤ 1
              for(in i=0;i<4;i++)
              {
                 int newx=x+dx[i];
                 int newy=y+dy[i];
                 
                 if(newx>=0 && newy>=0 && newx<row && newy<col && arr[newx][newy]==0 && dp[newx][newy]==-1)
                 {
                     q.push({newx,newy});
                     dp[newx][newy]=dp[x][y]+1;
                 }
             }
             
             
             
             
         }
         
         
         
     }
    

    int helper(vector<vector<int>>&arr)    //O(n*m)
    {
         int row=arr.size();
         int col=arr[0].size();
         vector<vector<int>>dp(row,vector<int>(col,-1));
         vector<vector<int>>dp2(row,vector<int>(col,-1));
         
         calculate(arr,dp,0,0);
         calculate(arr,dp2,row-1,col-1);
          
          
          int ans=INT_MAX;        // O(n*m)
          for(int i=0;i<row;i++)
          {          
              for(int j=0;j<col;j++)
              {
                   if(dp[i][j]>=0 && dp2[i])[j]>=0)
                   {
                       ans=min(ans, max(dp2[i][j],dp[i][j]));
                       
                   }
                  
                  
              }
          }
          if(ans==INT_MAX) return -1;
          return ans;
    }
