#include <bits/stdc++.h>
using namespace std;
stack<int>s;
     void insert_at_correct_pos(int x)
       {
        if(s.empty() || s.top()<=x)
           {
             s.push(x);
             return;
           }

           
 
           int a=s.top();
            s.pop();
            insert_at_correct_pos(x);
            s.push(a);
     }
     void  sort() 
     {
       if(s.empty()) return;
 
       int x=s.top();
       s.pop();
       sort();
       insert_at_correct_pos(x);
      } 
 
int main() {
 
	 int x;
	 s.push(1);
	 s.push(2);
	 s.push(3);
	 s.push(8);
	 s.push(10);
	 s.push(5);
 
	 sort();
	 while(!s.empty())
	 {
	 	cout<<s.top()<<" ";
	 	s.pop();
	 }
 
 
	return 0;
}