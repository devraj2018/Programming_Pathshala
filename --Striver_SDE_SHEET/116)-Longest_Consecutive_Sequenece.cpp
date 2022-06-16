#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
        unordered_map<int,int>mp;
       if(n==0 || n==1) return n;
        for(auto x:arr) mp[x]++;
    
        int res=INT_MIN;
        for(auto i : arr)
        {
            if(mp.find(i - 1) == mp.end())
            {
                int k = i;
                int len = 1;
                while(mp.find(k + 1) != mp.end())
                {
                    k++;
                    len++;
                }
                res = max(res, len);
            }
        }
        return res > 0 ? res : 1;
}