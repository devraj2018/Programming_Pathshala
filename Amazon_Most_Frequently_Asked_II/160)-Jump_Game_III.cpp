class Solution {
public:
    bool helper(vector<int>&arr,int start,vector<int>&visited,vector<bool>&ans)
    {
        
        if(arr[start]==0) return true;
        
        if(visited[start]!=0) return ans[start];
        visited[start]=1;
        bool res=false;
        
        if(start+arr[start]<arr.size()) res= res|| helper(arr,start+arr[start],visited,ans);
        if(start-arr[start]>=0) res= res|| helper(arr,start-arr[start],visited,ans);
        return ans[start]=res;
        
      
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> visited(n,0);
         vector<bool> ans(n,false);
        return helper(arr,start,visited,ans);
        
        
    }
};