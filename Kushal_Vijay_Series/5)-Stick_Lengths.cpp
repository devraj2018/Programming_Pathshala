#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<long long >arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int med=n/2;

    sort(arr.begin(),arr.end());
    long long ans=0;
   int i=0;
    while(i<n)
    {
          ans+= abs(arr[i]-arr[med]);
        i++;

    }
    cout<<ans;

    
  
}