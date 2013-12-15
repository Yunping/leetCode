
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {

        std::sort(num.begin(), num.end());
        
        int len = num.size();
        int min = INT_MAX;
        int sum = 0;
        int closestSum = 0;
        
        for (int i = 0; i < len - 2; ++i) {
            int m = i+1;
            int n = len - 1;
            while (m < n) {
                sum = num[i] + num[m] + num[n];
                if (sum == target)
                    return target;
                if (sum < target)
                    ++m;
                else
                    --n;
                    
                if (abs(sum - target) < min) {
                    closestSum = sum;
                    min = abs(sum - target);
                }
            }
        }
        
        return closestSum;
    }
};