class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       
         int lowest= to_string(low).size(); 
         int highest= to_string(high).size();
         vector<int>res;
        string digit="123456789";
        
        for(int size=lowest;size<=highest;size++)   // for every size 
        {
             for(int j=0;j<10-size;j++)     // generte all number
             {
                  string temp= digit.substr(j,size);
                  int num= stoi(temp);
                 
                  if(num>=low && num<=high) res.push_back(num);
             }
            
        }
        return res;
        
    }
};