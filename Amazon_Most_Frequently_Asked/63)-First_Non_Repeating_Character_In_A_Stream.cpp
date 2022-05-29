string Solution::solve(string s) {
  queue<char>q;
  string ans="";

  vector<int>freq(26,0);
  for(int i=0;i<s.length();i++)
  {
       if(freq[s[i]-'a']==0) q.push(s[i]); 
	   
	   freq[s[i]-'a']++;

       while(!q.empty() && freq[q.front()-'a']>1) q.pop();

       if(!q.empty()) ans.push_back(q.front());
       else ans.push_back('#');  
    
    
  }
  return ans;
}