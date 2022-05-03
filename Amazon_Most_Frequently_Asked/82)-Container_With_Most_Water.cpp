class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0,end=height.size()-1;
        
        int area=0;
        
        while(start<end)
        {
            area=max(area, (end-start)*min(height[start],height[end]));
            
            if(height[start]<=height[end])  start++;
            else  end--;
        }
        return area;
        
    }
};

/*    Check for Every Pair
 int area = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            // Calculating the max area
            area = max(area, min(A[j], A[i]) * (j - i));
        }
    }
    return area;
*/