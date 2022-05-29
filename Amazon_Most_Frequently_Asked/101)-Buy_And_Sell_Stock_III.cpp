class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int>left(n,0),right(n,0);
        
        int minn=prices[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],prices[i]-minn);
            minn=min(minn,prices[i]);
        }
        
        int maxx=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],maxx-prices[i]);
            maxx=max(maxx,prices[i]);
        }
        
        int ans=0;
        
        for(int i=1;i<n;i++)
        {
            ans=max(ans,left[i]+right[i]);
            
        }
        return ans;
        
    }
};