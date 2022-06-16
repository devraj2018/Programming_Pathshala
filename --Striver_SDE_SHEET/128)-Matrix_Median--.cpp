#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
   vector<int> res;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            res.push_back(matrix[i][j]);
        }
    }
    
    sort(res.begin(), res.end());
    int mid=res.size()/2;
   return res[mid];

}


===================== Yeh neeche approach chal nhoi rhi dobara try kr isko ===========

#include<bits/stdc++.h>
struct comp{
    bool operator()(vector<int>&a,vector<int>&b)
    {
        return a[0]>b[0];
    }
};
int getMedian(vector<vector<int>> &matrix)
{
        int n=matrix.size();
        int m=matrix[0].size();
    
    int total=n*m;
    int c1=0,c2=0;
    if(total%2==0)
    {
        c1=total/2;
        c2=total/2+1;
        
    }
    else
    {
        c1=total/2;
        c2=total/2;
    }
    priority_queue<vector<int>,vector<vector<int>>,comp>pq;
    for(int i=0;i<n;i++)
    {
        pq.push({matrix[i][0],i,0});
    }
    int count=0;
    int ans=0;
    while(count<c2)
    {
        count++;
        int ele=pq.top()[0];
        int x=pq.top()[1];
        int y=pq.top()[2];
        pq.pop();
        
        if(count==c1)
        {
            ans+=ele;
        }
        if(count==c2)
        {
            ans+=ele;
        }
        
        if(y+1<m)pq.push({matrix[x][y+1],x,y+1});
        
    }
    return (ans)/2;
    
    
}