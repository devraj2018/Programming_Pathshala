#include<bits/stdc++.h>
int maximumXor(vector<int> A)
{
    int maxXor=0;
    int mask=0;
    int maxPossible=0;
    
    unordered_set<int>prefixes;
    for(int i=31;i>=0;i--)
    { 
         mask = (mask | (1<<i));
         maxPossible= (maxXor | (1<<i));
        
         for(int i=0;i<A.size();i++)
         {
             prefixes.insert(A[i]&mask);
         }
        
         for(auto i:prefixes)
         {
             if(prefixes.find(maxPossible^i)!=prefixes.end())
             {
                 maxXor=maxXor | maxPossible;
                 break;
             }
         }
        prefixes.clear();
       }
    return maxXor;
}