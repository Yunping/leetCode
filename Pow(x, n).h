/*
Problem: Pow(x, n)
Implement pow(x, n).

========================================================

Author: Yunping, qufang83@gmail.com
Date: 10/02/2014
Difficulty: **
Review: ***
Solution: two methods

*/
class Solution {
public:
    double pow(double x, int n) {
        int abs_n = abs(n);
        double abs_ret = absPow1(x, abs_n);
        if (n < 0)
            return (1.0 / abs_ret);
        else
            return abs_ret;
    }

private:
    // method1
    double absPow1(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (equals(x, 0)) return 0;
        if (equals(x, 1)) return 1;
        if (equals(x, -1)) return (n & 0x1) ? -1 : 1;
        
        double ret = 1;
        while (n) {
            if (n & 0x1)
                ret *= x;
            x *= x;
            n >>= 1;
        }
        
        return ret;
    }
    
    // method2.
    double absPow(double x, int n) {
        if (equals(x, 0)) return 0;
        if (equals(x, 1)) return 1;
        if (equals(x, -1)) return (n & 0x1) ? -1 : 1;
        
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n & 0x1) {
            double t = absPow(x, (n-1)>>1);
            return (x * t * t);
        } else {
            double t = absPow(x, n>>1);
            return (t * t);
        }
    }
    
    bool equals(double a, double b) {
        return (a-b) < 0.0000001 && (a-b) > -0.0000001;
    }
};