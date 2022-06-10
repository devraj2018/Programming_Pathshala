bool areAnagram(string &str1, string &str2){
     vector<int>f1(26,0),f2(26,0);
    for(int i=0;i<str1.length();i++) f1[str1[i]-'a']++;
        for(int i=0;i<str2.length();i++) f2[str2[i]-'a']++;
    return f1==f2;
}