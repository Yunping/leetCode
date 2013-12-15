class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool positive = x > 0;
        x = positive ? x : -x;
        char s[100];
        sprintf(s, "%d", x);
        
        int len = strlen(s);
        for (int i = 0, j = len - 1; i < j; ++i, --j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
        
        int y = atoi(s);
        y = positive ? y : -y;
        return y;
    }
};

class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        int last = 0;
        while (x != 0) {
            last = x % 10;
            result = result * 10 + last;
            x = x/10;
        }
        
        return result;
    }
};