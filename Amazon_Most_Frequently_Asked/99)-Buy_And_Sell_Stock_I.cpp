class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int minn=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            ans=max(ans,prices[i]-minn);
            minn=min(minn,prices[i]);
        }
        return ans;
    }
};