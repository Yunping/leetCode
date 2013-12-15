class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        
        int orig = x;
        int reverse = 0;
        int last = 0;
        while (x != 0) {
            last = x % 10;
            reverse = 10 * reverse + last;
            x = x / 10;
        }
        
        return reverse == orig;
    }
};