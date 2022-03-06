//Given an array of integers and a number k, write a function that returns true if the given array can be divided into pairs such that 
//the sum of every pair is divisible by k.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[(k+arr[i]%k)%k]++;       //+k so that we can include negative number and last wala %k bcz
        }                               // if number is positive then +k increase this greater than k so 
        
        for(int i=0;i<arr.size();i++)
        {
            int r= (k+arr[i]%k)%k;
            
            if(r==0 && mp[r]%2!=0) return false;
            if( r!=0 && mp[r]!=mp[k-r]) return false;
                
            
        }
        return true;
        
    }
};