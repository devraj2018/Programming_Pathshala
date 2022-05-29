#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int n, x; 
    cin >> n >> x;
    vector<int> vec(n);
    for(int& i : vec) cin >> i;
    int moves = 0, mnSoFar = vec.back();
    for(int i = n-2; i >= 0; --i)
        {
        int delta = max(mnSoFar - vec[i] + 1, 0);
        int currMoves = (delta + x - 1) / x;

        vec[i] += currMoves * x;

        moves += currMoves;
        mnSoFar = vec[i]; 
        
    }
  cout << moves << endl;
}

int main(){
 
    
    int t=1; 
    cin >> t;
    while(t--) solve();
}