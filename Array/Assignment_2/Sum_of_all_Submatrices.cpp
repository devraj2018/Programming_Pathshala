#include<bits/stdc++.h>
using namespace std;
int main()
{
  int row,col;
  cin>>row>>col;
  int arr[row][col];
  for(int i=0;i<row;i++)
  {
      for(int j=0;j<col;j++)
      {
          cin>>arr[i][j];
      }
  }
  int sum=0;                      // Check for overflow condition and used variable accordingly
  for(int i=0;i<row;i++)
  {
      for(int j=0;j<col;j++)
      {
          sum+= (i+1)*(j+1)*(row-i)*(col-j);
      }
  }
   return sum;

}