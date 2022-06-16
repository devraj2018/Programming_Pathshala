#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
     vector<int>temp;
     temp.push_back(arr[0]);
      int ans=1;

      for( int i=1;i<n;i++)
          {
            if(arr[i]>temp.back())
                {
                   temp.push_back(arr[i]);
                   ans++;
                 }
             else
                {
                 int x =lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                 temp[x]=arr[i];
                }
           }

   return ans;
    
}
