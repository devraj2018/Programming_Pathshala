class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n=nums.size();
         long long product=1;
         int zero=0;
         int zero_index;
         for(int i=0;i<n;i++)
          {
           if(nums[i]==0) {zero++;zero_index=i;}
           else product*=nums[i];
          }
        vector<int>res(n,0);
        if(zero>=2) return res;
        
        if(zero==1)
        {
            res[zero_index]=(int)product;
            return res;
        }
        for(int i=0;i<n;i++)
        {
            res[i]=(int)product/nums[i];
            
        }
        return res;
        
        
    }
};
/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        
        for(int i=1;i<n;i++)
        {
            left[i]= left[i-1]*nums[i-1];
            right[n-i-1]=right[n-i]*nums[n-i];
        }
         vector<int> res(n);
         
        res[0]=right[0];
        res[n-1]=left[n-1];
        for(int i=1;i<n-1;i++)
        {
            res[i]=left[i]*right[i];
        }
        return res;
        
    }
};*/