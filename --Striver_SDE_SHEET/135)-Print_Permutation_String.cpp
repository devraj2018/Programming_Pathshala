void solve(string& s, vector<string>& res, int index){
 
   if(index>=s.length()){
      res.push_back(s);
      return;
     }

 for(int j=index; j<s.length(); j++) {

       swap(s[index],s[j]);
       solve(s,res,index+1);
       swap(s[index],s[j]);

   }
}
vector<string> findPermutations(string &s) {
    
     vector<string> res;
     int index = 0;
     solve(s, res, index);
     return res;
    
}