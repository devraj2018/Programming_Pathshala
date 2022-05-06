----------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------

In one move, you can either:

Increment the current integer by one (i.e., x = x + 1).
Double the current integer (i.e., x = 2 * x).

---------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int moves=0;
        int double_used=0;
        while(target>1 && double_used<maxDoubles)
        {
             if(target%2==0) 
             {
                 moves++;
                 double_used++;
                 target/=2;
             }
            else
            {
                moves++;
                target-=1;
            }
        }
        
        return moves +(target-1);
    }
};