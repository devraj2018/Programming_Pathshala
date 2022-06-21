void solve(string s,int k,string &ans,int fact)
 {
     if(k==0)
         {  ans.append(s);
             return;
         }

     ans.push_back(s[k/fact]);
     s.erase(s.begin()+k/fact);
     solve(s,k%fact,ans,fact/s.length());

}

 

string kthPermutation(int n, int k) {

     string s="";
     int fact=1;
     for(int i=1;i<=n;i++)
        {
           s.append(to_string(i));
           fact*=i;
         }

   fact/=n;
   string ans="";
   solve(s,k-1,ans,fact);
   return ans;

}