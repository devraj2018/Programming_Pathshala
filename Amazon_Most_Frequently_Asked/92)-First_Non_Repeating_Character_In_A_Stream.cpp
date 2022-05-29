string Solution::solve(string A) {

  unordered_map<char,int>freq;
  string ans="";
  queue<char>q;
  for(int i=0;i<A.length();i++)
  {
        freq[A[i]]++;
        if(freq[A[i]]==1) q.push(A[i]);

        while(!q.empty() && freq[q.front()]>1) q.pop();

        if(q.empty())
         ans+="#";
         else ans+=q.front();



  }
return ans;
}