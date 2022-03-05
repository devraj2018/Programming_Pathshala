int Solution::mice(vector<int> &A, vector<int> &B) {

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
  
    int maxx=0;
    for(int i=0;i<A.size();i++) maxx=max(maxx,abs(B[i]-A[i]));
 
    return maxx;
}