// If we use unordered map here then we have to write our own hash function
//Bcz in C++ for primitive data type there is no hash function implemented internally
// So Better to use TreeMap-->>  Not need of any hash function in orderedMap 
//And also there is no effect in time complexity of this question-->>let's see the implementation
class Solution {
public:
    void standard(int &denominator,int &numerator)
    {
         if(denominator==0) numerator = 1;  // For Vertical Line
         else if(numerator == 0) denominator = 1; // For Horizontal Line
         else if( (numerator<0 && denominator <0) || denominator< 0){ 
              numerator*=-1;      // Case for -a/-b=> a/b or a/-b=> -a/b or -a/b=> -a/b 
              denominator*=-1;    // We standardise in this way so we can easily find 
         }                        //- these values in map without missing edge cases
        
        
        
        
    }
    int maxPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        map<pair<int,int>,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
             int curr_max=0;                   
             int duplicate=0;
            
             for(int j=i+1;j<n;j++)
             {
                 //if(points[i][0]==points[j][0] && points[i][1]==points[j][1])  // Only to handle dupliactes
                 //  {
                 //    duplicates++;
                 //    continue;
                 //   }
                 
                 int delta_y= points[j][1]-points[i][1];   // Not using division with float to avoid precision error
                 int delta_x= points[j][0]-points[i][0];   //   1.234635 may be equal to 1.234679, Depends on System
                                                           // Also storing delta_x and delta_y seperately will be helpful in case
                                                           // -of Infinity slope
                 
                 int gcd= __gcd(abs(delta_x),abs(delta_y));  // Takes  log( max ( delta_x,delta_y ))  Time
                 
                  delta_x= delta_x/gcd;      //To reduce number to its lowest factor Like 8/12 =>2/3, 12/18=>2/3 Both are same
                  delta_y= delta_y/gcd;      // So to store frequency in map we need to standardized these
                   
                  standard(delta_x,delta_y);    // To handle Infinty slope and Sign Issues
                 
                  if(mp.find({delta_x,delta_y})!=mp.end())             // It takes log(n) time
                      mp[{delta_x,delta_y}]++;
                  else
                     mp[{delta_x,delta_y}]=1;
                 
                  curr_max=max(curr_max, mp[{delta_x,delta_y}]);
               }
            
             ans=max(ans,1+curr_max);      // In case of Duplicates Points => ans = max( ans, 1 + duplicates + curr_max)
             mp.clear();
         }
        return ans;
        
        
    }
};