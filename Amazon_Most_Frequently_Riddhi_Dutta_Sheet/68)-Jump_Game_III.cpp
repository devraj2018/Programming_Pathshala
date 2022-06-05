class Solution {
public:
    bool helper(int start,vector<int>& arr,vector<int>& visited)
    {
         if(arr[start]==0) return true;
        
         bool left=false,right=false;
         visited[start]=1;
        
         if(start-arr[start]>=0 &&  visited[start-arr[start]]==-1)
             left=helper(start-arr[start],arr,visited);
         if(start+arr[start]<arr.size() &&  visited[start+arr[start]]==-1)
             right=helper(start+arr[start],arr,visited);
        
         return left|| right;
             
       
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>visited(n,-1);
        
        return helper(start,arr,visited);
        
    }
};