------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------         0(nlogk) & 0(k)space         ----------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
    struct comp{
        public:
         bool operator()(const pair<int,string>&a,const pair<int,string>&b)
         {
             if(a.first<b.first) return false;
             if(a.first>b.first) return true;
             
             return (a.second <= b.second);
             
         }
        
    };
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
     
        unordered_map<string,int>mp;
        for(auto s:words) mp[s]++;
        
         priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
         for(auto x:mp)
           {
              pq.push({x.second,x.first});
              if(pq.size()>k) pq.pop();
            }
            int n=pq.size();
            vector<string>res(n);
            for(int i=n-1;i>=0;i--)
            {
             res[i]=pq.top().second;
             pq.pop();
            }
        return res;
       }
};
------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------         0(nlogn) & 0(n)space         -----------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------

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