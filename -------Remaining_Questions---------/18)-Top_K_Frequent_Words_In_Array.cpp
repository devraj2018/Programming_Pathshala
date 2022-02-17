class Solution {
    struct comp{
        public:
           bool operator()(const pair<int,string>p1,const pair<int,string>p2)
              {
                     if(p1.first<p2.first) return true;
                     if(p1.first>p2.first) return false;
               
                     return p1.second>p2.second;
             }
     };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mp;
        for(auto x:words)
            mp[x]++;
        
        vector<pair<int,string>>arr;
        for(auto x:mp)
        {
            arr.push_back({x.second,x.first});
        }
        priority_queue< pair<int,string>,vector<pair<int,string>>, comp>pq(arr.begin(),arr.end());
        
        vector<string>res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
            
        }
        return res;
        
    }
};