/*
Problem: Maximum Product Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/10/2014
Difficulty: ***^
Review: ****
Solution: DP. (My Own)
    di is the max product to A[i]. But only di can't determine the next di. Because if A[i] is negative, 
    the next di should be the most negative product before A[i] multiple A[i]. So we also need a fi
    to record the most negative product to A[i]
*/
class Solution {
public:
    int maxProduct(int A[], int n) {
        if (!A || n <= 0) return 0;
        
        // di is the max product to A[i].
        // fi is the max abs negative product to A[i].
        vector<int> d(n, 0);
        vector<int> f(n, 1);
        
        int max_product = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                d[i] = A[i];
                f[i] = min(0, A[i]);
            } else {
                if (A[i] >= 0) {
                    if (d[i-1] > 0)
                        d[i] = A[i] * d[i-1];
                    else
                        d[i] = A[i];
                    if (f[i-1] < 0)
                        f[i] = f[i-1] * A[i];
                } else {
                    // A[i] < 0
                    if (d[i-1] >= 0) {
                        d[i] = max(A[i] * f[i-1], A[i]);
                        f[i] = min(A[i], A[i] * d[i-1]);
                    } else {
                        d[i] = A[i] * f[i-1];
                        f[i] = A[i];
                    }
                }
            }
            
            max_product = max(max_product, d[i]);
        }
        
        return max_product;
    }
};