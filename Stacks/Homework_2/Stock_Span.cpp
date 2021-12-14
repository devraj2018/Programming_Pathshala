class Solution
{    public:
     
    vector <int> calculateSpan(int price[], int n)
    {   vector<int> res(n,1);
        stack<pair<int,int>>s;
        s.push({price[0],0});
        for(int i=1;i<n;i++)
        {   while(!s.empty() && s.top().first<=price[i]) s.pop();
                
             if(!s.empty()) res[i]=i-s.top().second;
             else res[i]=i+1;
            
             s.push({price[i],i});
       }
        return res;
    }
};
