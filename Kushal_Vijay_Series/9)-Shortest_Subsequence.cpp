#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;

    int minn=INT_MAX;
    char minchar;
    unordered_map<char,int>mp; 
    for(int i=0;i<s.length();i++)
    {
          mp[s[i]]++;
          
          if(mp[s[i]]<minn)
          {
              minn=mp[s[i]];
              minchar=s[i];
          }
    }

    int count=mp[minchar];
    for(int i=0;i<=count;i++)
     cout<<minchar;

     


}