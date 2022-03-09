#include<bits/stdc++.h>
using namespace std;
int main()
{ string str;
  cin>>str;
  stack<char>s;
  if(str.length()==1)
    {
       cout<<str[0]<<endl;
       return 0;
    }
  int i=0;
  while(i<str.length())
     {   if(s.empty())
          {
           s.push(str[i]);
           i++;
           continue;
           }
       
      s.push(str[i]); 
      int count=0;
      while(!s.empty() && s.top()==str[i])
        {s.pop();
         count++;
        }
        if(count==1) s.push(str[i]);
        i++;
  }
  string ans="";
  while(!s.empty())
  {
  	ans.push_back(s.top());
  	s.pop();
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;

}