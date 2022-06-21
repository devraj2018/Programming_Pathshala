#include<bits/stdc++.h>
bool isPalin(int i, int j, string& s){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}
int solve(int i, int n, string& s, vector<int>& dp){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];

    int cost = INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalin(i, j, s)){
            int cut = 1 + solve(j+1, n, s, dp);
            cost = min(cut, cost);
        }
    }
    return dp[i] = cost;
}
int palindromePartitioning(string s) {
    int n = s.length();
    vector<int> dp(n, -1);

    int ans = solve(0, n, s, dp)-1;
    return ans;
}