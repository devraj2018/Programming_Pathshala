#include <bits/stdc++.h>
using namespace std;

int helper(string s,int capacity)
{    unordered_set<char>st;
     int ans=0;
     int curr_cap=capacity;
	 for(int i=0;i<s.length();i++)
	 {
	     if(st.find(s[i])==st.end() && curr_cap>0)
	 	  {
	 	  	curr_cap--;
	 	  	st.insert(s[i]);
	 	  }
	 	  else if(st.find(s[i])!=st.end())
	 	  {
	 	  	curr_cap++;
	 	  	curr_cap=min(curr_cap,capacity);
	 	  	st.erase(s[i]);
	 	  }
	 	  else
 	 	  	ans++;

	  }
	  return ans/2;

}

int main() {
    string s;
    cin>>s;
    int cap;
    cin>>cap;
    int ans=helper(s,cap);
    cout<<ans<<" ";
	return 0;
}