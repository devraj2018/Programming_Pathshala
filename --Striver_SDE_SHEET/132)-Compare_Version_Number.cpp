#include<bits/stdc++.h>
int compareVersions(string a, string b) 
{
    // Write your code here
    int asize=a.length();
    int bsize=b.length();

    vector<string> anum;
    vector<string> bnum;
    string temp="";
    for(int i=0;i<asize;i++){


        if(a[i]=='.'){
            anum.push_back(temp);
            temp="";
        }else{
            temp+=a[i];
        }
    }
    anum.push_back(temp);
    temp="";
    
    for(int i=0;i<bsize;i++){
        
        if(b[i]=='.'){
            bnum.push_back(temp);
            temp="";
        }else{
            temp+=b[i];
        }
    }
    bnum.push_back(temp);
    temp="";
    
    int n=anum.size();
    int m=bnum.size();
    

    
    int maxl=max(n,m);
    
    for(int i=0;i<maxl;i++){
        string v1=i<n?anum[i]:"0";
        string v2=i<m?bnum[i]:"0";
        if(v1 > v2){
            if(v2.size()>v1.size()){
                return -1;
            }else{
                return 1;
            }
         // if the value of v1 is smaller, but if its length is greater then v2 then it is latest means A is latest so return 1.
        /* example A = 1.2.03, B =1.2.3
        A= 1203;
        B=123
        A is latest 
  
        */
        }else if(v2 > v1){ // 3 > 03
            if(v1.size()>v2.size()){ // but 03 size is 2 and 3 size is 1. so 03 is latest.
                return 1;
            }else{
                return -1;
            }

        }
    }
    return 0;


}