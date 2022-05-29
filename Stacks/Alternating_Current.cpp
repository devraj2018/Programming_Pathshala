#include<bits/stdc++.h>
using namespace std;
int main()
{
  string str;
  cin>>str;
  int n=str.length();
  stack<char>s;
  if(str.length()&1)
   {
       cout<<"No"<<endl;
       return 0;
   }



  int i=0;
  while(i<str.length())
  {  
       if(s.empty())
       {   s.push(str[i]);
           i++;
           continue;
       }
       char ele=str[i];
       int count=0;
       while(!s.empty() && s.top()==ele)
        { count++;
          s.pop();
        }
        while(i<n && str[i]==ele)
        { count++;
         i++;
        }
        if(count%2==1)
        {
        	s.push(ele);
        }
       
  }
 
  if(s.empty())
  {
  	cout<<"Yes"<<endl;
  }
  else
  cout<<"No"<<endl;


}