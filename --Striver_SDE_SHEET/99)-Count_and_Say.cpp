string writeAsYouSpeak(int n) 
{
	if(n==1)
        return "1";
    if(n==2)
        return "11";
        
        string ans="11";
        for(int i=3;i<=n;i++)
        {
            ans=ans+'$';
            
            string temp="";
            int count=1;
            for(int j=1;j<ans.size();j++)
            {
                if(ans[j]==ans[j-1])
                {
                    count++;
                }
                else if(ans[j]!=ans[j-1])
                {
                    temp=temp+to_string(count);
                    temp.push_back(ans[j-1]);
                    count=1;
                }
            }
            ans=temp;
        }
    return ans;
    
}