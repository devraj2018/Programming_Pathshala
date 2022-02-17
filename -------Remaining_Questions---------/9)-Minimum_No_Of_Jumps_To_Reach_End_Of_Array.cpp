int Solution::jump(vector<int> &A) {
    int n=A.size();
    int left=0,right=0;
    int maxpossible=0;
    int res=0;
    while(right<n-1)
    {
         for(int i=left;i<=right;i++)
         { maxpossible=max(maxpossible,i+A[i]);
         }
         left=right+1;
         right=maxpossible;
         res++;
         if(left>right)
         return -1;


    }
    return res;
}