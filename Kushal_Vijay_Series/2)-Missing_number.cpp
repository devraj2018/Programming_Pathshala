#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    long long int xorr=0;
   int x;
    for(int i=1;i<n;i++)
    { cin>>x;
       
       xorr=xorr^x;
       xorr=xorr^i;

    }
    xorr=xorr^n;

    xorr=(int)xorr;
    cout<<xorr;
   

   



}