class Solution {
public:
    bool isRobotBounded(string s) {
        
        int start_x=0,start_y=0;
        int dir=90;
        
        for(int j=0;j<4*s.length();j++)
        {
            int i=j%s.length();
            
            if(s[i]=='R') dir= (360+ dir-90)%360;
            else if(s[i]=='L') dir= (dir+90)%360;
            else if(dir==0) start_x=start_x+1;
            else if(dir==90) start_y=start_y+1;
            else if(dir==180) start_x=start_x-1;
            else if(dir==270) start_y=start_y-1;
            
                
        }
        
        if(dir==90 && start_x==0 && start_y==0) return true;
        return false;
         
        
    }
};