class Solution {
public:

    //-----------O(n) Space Method --------------------[first tell this to the interviewer] // 
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        int left_min=prices[0];
        int right_max=prices[n-1];
        for(int i=1;i<n;i++)
        {   left_min=min(left_min,prices[i]);
            pre[i]=max(pre[i-1],prices[i]-left_min);
         
            right_max=max(right_max,prices[n-i-1]);
            suff[n-i-1]=max(suff[n-i],right_max-prices[n-i-1]);
         
            
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,pre[i]+suff[i]);
        }
        return ans;
        
    }
};

//------------------O(1) Space method ,Most Optimal --------//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int state0=INT_MIN;
        int state1=0;
        int state2=INT_MIN;
        int state3=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            state3=max(state3,state2+prices[i]);
            state2=max(state2,state1-prices[i]);
            state1=max(state1,state0+prices[i]);
            state0=max(state0,-prices[i]);     
        }    
        return max(state1,state3);
    }
};