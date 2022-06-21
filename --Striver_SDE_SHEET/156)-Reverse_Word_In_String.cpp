#include<bits/stdc++.h>
string reverseString(string s)
{
    vector<string>res;
    int n=s.size();
    int i=0;
    while(i<n)
    {
        string temp="";
        while(i<n && s[i]!=' ')
        {
            temp+=s[i];
            i++;
        }
        i++;
        if(temp.size()!=0) res.push_back(temp);
    }
    reverse(res.begin(),res.end());
    
    string ans="";
    for(int i=0;i<res.size();i++){
        ans+=res[i];
        ans+=" ";
    }
    ans.pop_back();
    return ans;
}