class Solution {
public:
    int maxVowels(string s, int k) {
        int i;
        int currcount=0;
        for(i=0;i<k;i++)
        {  char x= s[i];
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
                currcount++;
        }
        int maxc=currcount;
        int n=s.length();
        for(int j=i;j<n;j++)
        { 
            char x= s[j];
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
                currcount++;
             char y= s[j-k];
            if(y=='a' || y=='e' || y=='i' || y=='o' || y=='u')
                currcount--;
            
            maxc=max(maxc,currcount);
            
            
        }
        return maxc;
        
    }
};