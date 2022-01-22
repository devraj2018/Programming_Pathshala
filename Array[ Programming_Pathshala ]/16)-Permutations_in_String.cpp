class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0),freq2(26,0);
        if(s1.length()>s2.length()) return false;
        
        for(int i=0;i<s1.length();i++)
           {
             freq1[s1[i]-'a']++;
             freq2[s2[i]-'a']++;
           }
        int k=s1.length();   //This should be equal to window size
    
        if(freq1 == freq2) return true;
        
        for(int i=k;i<s2.length();i++)
            {    freq2[s2[i]-'a']++;
                 freq2[s2[i-k]-'a']--;
                 
                  if(freq1 == freq2) return true;
                 
             
           }
        return false;
        
    }
};