class Solution {
public:
    static bool comp(const pair<string,string>&a,const pair<string,string>&b)
    {
        if(a.second<b.second) return true;
        if(a.second>b.second) return false;
        
        return a.first<b.first;
   }
    vector<string> reorderLogFiles(vector<string>& logs) {
     
        vector<string>digits;
        vector<pair<string,string>>letter;
        
        for(auto &s:logs)
        {
            if(s[s.size()-1]>='0' && s[s.size()-1]<='9')
                 digits.push_back(s);
            else
            {   int i=0;
                while(s[i]!=' ') i++;
                
                string ident=s.substr(0,i);
                string content=s.substr(i+1);
             
                letter.push_back({ident,content});
            }
       }
        
       sort(letter.begin(),letter.end(),comp); 
       vector<string>res;
       for(int i=0;i<letter.size();i++)
       {
            string temp= letter[i].first+" "+letter[i].second;
           res.push_back(temp);
           
       }
        for(int i=0;i<digits.size();i++)
       {
             
            res.push_back(digits[i]);
           
       }
        return res;
        
    }
};