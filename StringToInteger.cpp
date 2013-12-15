/*
Forgot to consider that the return value may be out of the range of int
*/

class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        bool positive = true;
        const char* a = str;
        while (a && *a == ' ')
            ++a;
        
        if (a) {
            if (*a == '+')
                ++a;
            else if (*a == '-') {
                ++a;
                positive = false;
            }
        }
        
        while (*a != '\0') {
            if (*a < '0' || *a > '9')
                break;
            
            if (positive)
                ret = 10 * ret + (*a - '0');
            else
                ret = 10 * ret - (*a - '0');
            
            if (positive && ret < 0) {
                ret = INT_MAX;
                break;
            }
            if (!positive && ret > 0) {
                ret = INT_MIN;
                break;
            }
            ++a;
        }
        
        return ret;
    }
};