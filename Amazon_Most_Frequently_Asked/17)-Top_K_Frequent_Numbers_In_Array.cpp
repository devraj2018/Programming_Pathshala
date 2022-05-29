class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums)
            mp[x]++;
         vector<pair<int,int>>arr;
        for(auto x:mp)
        {
            arr.push_back({x.second,x.first});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq(arr.begin(),arr.end());
        vector<int>res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
        
    }
};