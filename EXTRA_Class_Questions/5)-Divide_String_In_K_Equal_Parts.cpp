#include <iostream>
using namespace std;

void helper(string s,int k)
{  string temp;
	for(int i=0;i<s.length();i+=k)
	{ temp=s.substr(i,k);        // s.substr(fromIndex,length)  s.substr(1,10)-->create substring from 
	  cout<<temp<<endl;          //                               index 1 and having length
	}
}

int main() {

	string s;cin>>s;int k;cin>>k;
	if(s.length()%k !=0) cout<<"Not Possible";
	else helper(s,k);
}