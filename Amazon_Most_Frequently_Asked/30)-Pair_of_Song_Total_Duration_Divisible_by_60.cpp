class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        
        int ans=0;
        
        for(int i=0;i<time.size();i++)
        {
             if(mp.find(60-time[i]%60)!=mp.end())
             {
                 ans+= mp[60-time[i]%60];
             }
             else if(time[i]%60==0 && mp.find(0)!=mp.end())        //  For Exact Divisble  60,120,180......
                ans+= mp[0];
             mp[time[i]%60]++;
        }
        return ans;
    }
};



--------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------



class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        vector<int>freq(60,0);
        
        for(int i=0;i<time.size();i++) freq[time[i]%60]++;
        
        long long ans=0;
        
        for(int i=1;i<=29;i++)  ans+= (long long)freq[i]*freq[60-i];
      
        
         if(freq[0]!=0) ans+= ((long long)freq[0]*(freq[0]-1))/2;
         if(freq[30]!=0) ans+= ((long long)freq[30]*(freq[30]-1))/2;
        
        return (int)ans;
            
            
        
        
    }
};