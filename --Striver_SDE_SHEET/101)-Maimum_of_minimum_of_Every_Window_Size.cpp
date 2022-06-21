#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> prevSml(n), nxtSml(n);
    stack<int> st;
    vector<int> res(n+1, INT_MIN);
    
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(st.empty()){
            prevSml[i]=-1;
        }else{
            prevSml[i]=st.top();
        }
        st.push(i);
    }
    while(!st.empty())    st.pop();
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && a[st.top()]>=a[i]){
            st.pop();
        }
        if(st.empty()){
            nxtSml[i]=n;
        }else{
            nxtSml[i]=st.top();
        }
        st.push(i);
    }
    
    for(int i=0; i<n; i++)
    {
        int windowSize = nxtSml[i]-prevSml[i]-1;
        res[windowSize] = max(res[windowSize], a[i]);
    }
    for(int i=n-1; i>=1; i--)
    {
        res[i]=max(res[i], res[i+1]);
    }
    vector<int> temp;
    copy(res.begin()+1, res.end(), back_inserter(temp));
    return temp;
}