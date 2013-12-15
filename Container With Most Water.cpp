class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 1;
        int j = height.size();
        int max = 0;
        while (j > i) {
            int cur_height = height[j-1] < height[i-1] ? height[j-1] : height[i-1];
            int cur = (j-i) * cur_height;
            max = cur > max ? cur : max;
            
            if (height[i-1] < height[j-1]) {
                while (++i < j && height[i-1] <= cur_height); 
            } else {
                while (--j > i && height[j-1] <= cur_height);
            }
        }
        
        return max;
    }
};