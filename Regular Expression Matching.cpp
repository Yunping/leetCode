class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function   
        if (!s && !p) return true;
        if (!s || !p) return false;
        
        while (*s != '\0' && *p != '\0') {
            switch (*p) {
                case '.':
                    ++p;
                    ++s;
                    break;
                case '*':
                    ++p;
                    while (*s != '\0') {
                        if (isMatch(s, p))
                            return true;
                        ++s;
                    }
                    return false;
                    break;
                default:
                    if (*s == *p) {
                        ++s;
                        ++p;
                    } else
                        ++p;
            }
            ++s;
        }
        
        if (*s != '\0') return false;
        
        return true;
    }
};