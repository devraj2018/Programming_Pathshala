#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;

   int maxx=0;

   int i=0,n=s.length();
   while(i<n)
   {
         int curr_len=0;
         int curr_char=s[i];

         while(i<n && s[i]==curr_char)
         {
             curr_len++;
             i++;
         }

       maxx=max(maxx,curr_len);
 
   }  
   cout<<maxx;
  
}