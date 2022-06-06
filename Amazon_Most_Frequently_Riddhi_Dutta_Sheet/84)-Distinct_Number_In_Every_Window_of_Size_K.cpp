vector<int> Solution::dNums(vector<int> &A, int B) {

  unordered_map<int,int>mp;
  vector<int>res;
  for(int i=0;i<B;i++)
  {
      mp[A[i]]++;
  }
  res.push_back(mp.size());
  for(int i=B;i<A.size();i++)
  {
       mp[A[i]]++;
       mp[A[i-B]]--;

       if(mp[A[i-B]]==0) mp.erase(A[i-B]);
        res.push_back(mp.size());

  }
  return res;


}