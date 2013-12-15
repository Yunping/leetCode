class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!haystack || !needle) return 0;
        
        char *cur = haystack;
        do {
            char* s = cur;
            char* d = needle;
            while (*s == *d && *d != '\0') {
                ++s;
                ++d;
            }
            if (*d == '\0')
                return cur;
            if (*s == '\0')
                return 0;
        } while (*cur++ != '\0');
        
        return 0;
    }
};