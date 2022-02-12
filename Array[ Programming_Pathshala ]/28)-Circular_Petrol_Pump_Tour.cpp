/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

class Solution{
  public:
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
        {
           int total_d=0;
           int total_p=0;
           for(int i=0;i<n;i++)
              {
                 total_p+= p[i].petrol;
                 total_d+= p[i].distance;
              }
            if(total_p<total_d) return -1;
            int curr_sum=0;
            int start=0;
            for(int i=0;i<n;i++)
               {
                   curr_sum+= p[i].petrol-p[i].distance;
                
                  if(curr_sum<0)
                     {
                        start=i+1;
                        curr_sum=0;
                     }
               }
           return start;
    }
};
