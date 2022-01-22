#include <bits/stdc++.h>
using namespace std;

int MAX(vector<int>&arr,int start,int end)
{
    if(start==end)
     return arr[start];
 
    int mid=start +(end-start)/2;
    int leftmax=MAX(arr,start,mid);
    int rightmax=MAX(arr,mid+1,end);

    return max(leftmax,rightmax);


}
vector<int> MAX_MIN(vector<int>&arr,int start,int end)
{
      if(start==end)
       return {arr[start],arr[start]};
      
      int mid=start+(end-start)/2;
      vector<int> left_maxmin= MAX_MIN(arr,start,mid);
      vector<int> right_maxmin= MAX_MIN(arr,mid+1,end); 

      int minn=min(left_maxmin[0],right_maxmin[0]);
      int maxx=max(left_maxmin[1],right_maxmin[1]);

      return {minn,maxx};

}
int main() {
    int n,k;
    cin>>n;
     vector<int>arr(n,0);
   
    for(int i=0;i<n;i++)
    cin>>arr[i];

    int maxx= MAX(arr,0,n-1);
    cout<<maxx<<endl;

    vector<int> res = MAX_MIN(arr,0,n-1);
    cout<<"Minimum--> "<<res[0]<<" and Maximum is-->>"<<res[1];
}