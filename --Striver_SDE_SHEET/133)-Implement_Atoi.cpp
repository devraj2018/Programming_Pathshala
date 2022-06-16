int atoi(string str) {
    
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            ans =ans*10 +(str[i]-'0');
        }
        
    }
    if(str[0]=='-') return -1*ans;
    return ans;
}