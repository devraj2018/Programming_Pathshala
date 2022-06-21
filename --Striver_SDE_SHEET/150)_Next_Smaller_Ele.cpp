#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &A, int n)
{
   
    stack<int>s;
    vector<int> res(n,-1);
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()>=A[i])
        s.pop();

        if(s.empty())
        res[i]=-1;
        else 
         res[i]=s.top();
        s.push(A[i]);


    }
    return res;
}