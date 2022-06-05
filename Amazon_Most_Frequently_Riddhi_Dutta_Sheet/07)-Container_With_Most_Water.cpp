class Solution {
public:
    int maxArea(vector<int>& height) {
        
          int area=0;
          int n=height.size();
          
          int i=0,j=n-1;
          while(i<j)
          {
              area=max(area, min(height[i],height[j])*(j-i));
              
              if(height[i]<=height[j]) i++;
              else j--;
               
          }
        return area;
    }
};

/*
    class Solution {
public:
    int maxArea(vector<int>& height) {
       
        int area=0;
        int n=height.size();
        for(int i=0;i<n;i++)
        {
             for(int j=i+1;j<n;j++)
             {
                 area=max(area, min(height[i],height[j])*(j-i));
             }
         }
        return area;
    }
};
*/