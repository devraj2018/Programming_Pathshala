class Solution
{   public:
    static bool comp(Item I1,Item I2)
     {   return I1.value*I2.weight >= I2.value*I1.weight;
     }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double ans=0;
        for(int i=0;i<n;i++)
        {
             if(W - arr[i].weight>=0)
             {
                  ans+= arr[i].value;
                  W-= arr[i].weight;
             }
             else
             {
                 double fr=  W*(1.0)/(arr[i].weight)*arr[i].value;
                 ans+= fr;
                 break;
             }
         }
        return ans;
      }
        
};