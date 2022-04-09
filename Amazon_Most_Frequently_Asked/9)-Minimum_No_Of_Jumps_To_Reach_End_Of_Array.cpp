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
    
    bool helper(int start,vector<int>& arr,vector<bool>& visited)
    {
         if(arr[start]==0) return true;
         
         if(visited[start]) return false;
        
         visited[start]=true;
         bool left=false;
         bool right=false;
        
         if(start-arr[start]>=0) left=helper(start-arr[start],arr,visited);
         if(start+arr[start]<arr.size()) right=helper(start+arr[start],arr,visited);
        
         if(left || right) return true;
        
         return false; 
        
    }
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        vector<bool>visited(n,false);
        
        return helper(start,arr,visited);
        
    }
};