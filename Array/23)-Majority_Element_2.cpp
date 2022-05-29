class Solution {
public:
    //---It can have atmost 2 Majority ELe ----//
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0;
        int m1=0,m2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
             if(nums[i]==m1)  c1++;
             else if(nums[i]==m2) c2++;
             else if(c1==0)
                { m1=nums[i];c1=1;}
             else if(c2==0)
                { m2=nums[i]; c2=1;}
             else
                {  c1--;c2--; }
        }
        
        c1=0,c2=0;
        for(auto x:nums)
        {
            if(x==m1) c1++;
            else if(x==m2)c2++;
        }
        
       if(c1>n/3 && c2>n/3)  return {m1,m2};
       else if(c1>n/3)  return {m1};
       else if (c2>n/3) return {m2};
       
       return {};
        
        
    }
};