#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long a,b;
   cin>>a>>b;
   bool ans=false;
   queue<long long>q;
   q.push(a);
   int minsteps=0;        // if(a==b) minsteps=0;

   while(!q.empty())
   {    
        long long curr=q.front();                       //Take pair of queue or minsteps++;
        q.pop();                                        //Modify_according_to_given_conditions

        long long newa=2*curr,newb=curr*10+1;
        if(newa==b || newb==b)
           {
             ans=true;
             break;
           }
        if(newa<b)
          q.push(newa);
        if(newb<b)
          q.push(newb);

   }

   if(ans)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;

}