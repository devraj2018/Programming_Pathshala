string SubStr(string s, int low, int high)
 {
      string ans="";
      for (int i = low; i <= high; ++i) ans+=s[i];
      return ans;
 }

 vector<int> stringMatch(string &s, string &p) {

    if(p.length()>s.length()) return {-1};
    vector<int> v;
    string ans="";
    for(int k=0;k<p.length();k++) ans+=s[k];
 
    int i=0,j=p.length()-1;
     while(j<s.length()){
          if(p==ans) v.push_back(i);
          i++;
          j++;
          ans+=s[j];
          ans.erase(0,1);
      }
 return v;

}