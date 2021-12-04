class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currmin=INT_MAX;
        int ans=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            currmin=min(currmin,prices[i]);
            
            ans=max(ans,prices[i]-currmin);
            
            
        }
        if(ans<=0)
            return 0;
        return ans;
        
    }
};