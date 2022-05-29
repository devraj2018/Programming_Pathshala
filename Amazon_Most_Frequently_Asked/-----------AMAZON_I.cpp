====================                Round -1     ===================================== 
 Ques-1

    N light bulbs are connected by a wire. Each bulb has a switch associated with it, 
    however due to faulty wiring, a switch also changes the state of all the bulbs to 
    the right of current bulb. Given an initial state of all bulbs, find the minimum 
    number of switches you have to press to turn on all the bulbs. You can press the 
    same switch multiple times. 

    Note: 0 represents the bulb is off and 1 represents the bulb is on. 


 Ques-2

    There are n gas stations along a circular route, where the amount of gas at the ith 
    station is gas[i].
    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the 
    ith station to its next (i + 1)th station. You begin the journey with an empty tank at
    one of the gas stations.

    Given two integer arrays gas and cost, return the starting gas station 
    index if you can travel around the circuit once in the clockwise direction,
    otherwise return -1. If there exists a solution, it is guaranteed to be unique



====================                Round -2     =================================    
Ques-1
Given a matrix of dimension m*n where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
2 : Covid +ve person
1 : Normal person
0 : There is no one.

In one unit of time an infected person at index [i,j] can infect normal person at in all the four direction (up, down, left and right).
Determine what is the minimum time required so that all the person become infected.

Initial state:
{2, 1, 0, 2, 1}
{1, 0, 1, 2, 1}
{1, 0, 0, 2, 1}

After 1 unit of time:
{2, 2, 0, 2, 2}
{2, 0, 2, 2, 2}
{1, 0, 0, 2, 2}

Final state, after 2 units of time:
{2, 2, 0, 2, 2}
{2, 0, 2, 2, 2}
{2, 0, 0, 2, 2}
All person will be infected in 2 time frames.

Time complexity:  (4*row*col) == O(row*col)
Space complexity  O(row*col)


int Solution(vector<vector<int>>&grid)
{
      int row=grid.size();
      int col=grid[0].size();
      
      queue<vector<int>>q;
      int count_normal=0;
     
      for(int i=0;i<row;i++)
      {
          for(int j=0;j<col;j++)
          {
              if(grid[i][j]==1) count_normal++;
              else if(grid[i][j]==2) {
                  q.push({i,j,0});
                  
              }
          }
      }
      
      int dx[4]={-1,1,0,0};
      int dy[4]={0,0,-1,1};
      
      int infected=0;
      int ans=0;
      
      while(!q.empty())
      {
           int x=q.front()[0];
           int y=q.front()[1];
           int time=q.front()[2];
           ans=max(ans,time);
           
           q.pop();
           
           for(int i=0;i<4;i++)
           {
               int new_x= x+dx[i];
               int new_y= y+dy[i];
               
               if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && grid[new_x][new_y]==1)
               {    infected++;
                    grid[new_x][new_y]=2;
                    q.push({new_x,new_y,time+1});
                   
               }
           }
           
       }
       
       if(infected!=count_normal) return -1;
       
       return ans;
     
}


















Ques-2


Given M sorted lists of variable length, efficiently compute the smallest range, including at least one element from each list.

For example,
Input: 4 sorted lists of variable length

[ 3, 6, 8, 10, 15 ]
[ 1, 5, 12 ]
[ 4, 8, 15, 16 ]
[ 2, 6 ]

Output:

The minimum range is 4–6


Input: 4 sorted lists of variable length

[ 2, 3, 4, 8, 10, 15 ]
[ 1, 5, 12 ]
[ 7, 8, 15, 16 ]
[ 3, 6 ]

Output:

The minimum range is 4–7 


Time complexity: O(M*N*logM)
Space complexity:  O(M)


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& lists) {
         
         int M=lists.size();
            
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    
    int curr_max=INT_MIN;
    for(int i=0;i<M;i++)
    {
        
        
        pq.push({lists[i][0],{i,0}});
        curr_max=max(curr_max,lists[i][0]);
     }
           vector<int>res(2);
     
     int range=INT_MAX;
     while(!pq.empty())
     {
          int minele=pq.top().first;
          int i=pq.top().second.first;
          int j=pq.top().second.second;
          
          pq.pop();
          
         int rng=curr_max-minele;
         if(rng<range){
             range=rng;
             res[0]=minele;
             res[1]=curr_max;
            }
          
     
          if(j+1< lists[i].size())
          {
              pq.push({lists[i][j+1],{i,j+1}});
              curr_max=max(curr_max,lists[i][j+1]);
          }
          else
             break;
         
     }
     
     return res;
     }
};





