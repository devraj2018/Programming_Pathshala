int Solution::seats(string A) {
    
    int n=A.length();
    int mod=1e7+3;

    vector<int>pos;    //  To store position of 'X'
    int count=0;

    for(int i=0;i<n;i++)
    {
        if(A[i]=='x')
        {   pos.push_back(i-count);   //  (i-count) bcz it will give from mid how many position to be shifted
            count++;
        }
    }


    if(count==0 || count==n) return 0;
    int median_index= (count)/2;
    int ans=0;
    for(int i=0;i<count;i++)
    {
        ans = (ans%mod + abs(pos[i]-pos[median_index])%mod)%mod;
    }
    return ans;
     


}