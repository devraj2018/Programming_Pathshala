-------------------    Jump Game I -----------------------------
class Solution {
public:
    bool canJump(vector<int>& nums) {
         int maxreachable=0;
         for(int i=0;i<nums.size();i++)
           {
               if(i>maxreachable) return false;
               maxreachable=max(maxreachable,i+nums[i]);
           }
        return true;
     }
};
-------------------    Jump Game II ----------------------------
int Solution::jump(vector<int> &A) {
    int n=A.size();
    int left=0,right=0;
    int maxpossible=0;
    int res=0;
    while(right<n-1)
    {
         for(int i=left;i<=right;i++) maxpossible=max(maxpossible,i+A[i]);
       
         left=right+1;
         right=maxpossible;
         res++;
         if(left>right) return -1;
   }
    return res;
}

-------------------    Jump Game III ------------------------
class Solution {
public:
    bool helper(vector<int>& arr, int start,vector<int>& visited,int n,vector<bool>& ans)
    {
          
          if(arr[start]==0) return true;
        
          if(visited[start]==1) return ans[start];
        
          visited[start]=1;
          bool left=false,right=false;
        
          if(start+arr[start]<n) right=helper(arr,start+arr[start],visited,n,ans);
          if(start-arr[start]>=0) left=helper(arr,start-arr[start],visited,n,ans);
        
         return ans[start]= left|| right;
        
        
        
        
        
        
    }
    bool canReach(vector<int>& arr, int start) {
      
        int n=arr.size();
        vector<int>visited(n,-1);
          vector<bool>ans(n);
        
        return helper(arr,start,visited,n,ans);
    }
};