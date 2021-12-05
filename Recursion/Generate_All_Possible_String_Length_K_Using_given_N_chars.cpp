#include<bits/stdc++.h>
using namespace std;

void Generate(char arr[],int &n,int curr_I,int &k,vector<string>&all,string curr)
{
     if(curr_I==k)
     {
         all.push_back(curr);
         return;
     }
     string temp;
     for(int i=0;i<n;i++)
     {    temp=curr;
          temp.push_back(arr[i]);
          Generate(arr,n,curr_I+1,k,all,temp );
     }



}

int main()
{
      int n,k;
      cin>>n>>k;
      char arr[n];
      for(int i=0;i<n;i++)
      cin>>arr[i];
      
     vector<string>all;
     string curr="";
     Generate(arr,n,0,k,all,curr);

     for(auto x:all)
     cout<<x<<endl; 


}
