class Solution {
public:
    string addBinary(string a, string b) {
        size_t len_a = a.length();
        size_t len_b = b.length();
        int i = len_a - 1;
        int j = len_b - 1;
        string sum;
        int extra = 0;
        for (; i >= 0 && j >= 0; --i, --j) {
            int bit_a = charToInt(a[i]);
            int bit_b = charToInt(b[j]);
            if (bit_a < 0 || bit_b < 0) return "";
            int bit_c = bit_a + bit_b + extra;
            if (bit_c >= 2) {
                bit_c = bit_c % 2;
                extra = 1;
            } else {
                extra = 0;
            }
            
            sum.insert(sum.begin(), intToChar(bit_c));
        }
        
        while (i >= 0) {
            int bit_a = charToInt(a[i]);
            if (bit_a < 0) return "";
            int bit_c = bit_a + extra;
            if (bit_c == 2) {
                bit_c = 0;
                extra = 1;
            } else
                extra = 0;
                
            sum.insert(sum.begin(), intToChar(bit_c));
            --i;
        }
        
        while (j >= 0) {
            int bit_b = charToInt(b[j]);
            if (bit_b < 0) return "";
            int bit_c = bit_b + extra;
            if (bit_c == 2) {
                bit_c = 0;
                extra = 1;
            } else
                extra = 0;
                
            sum.insert(sum.begin(), intToChar(bit_c));
            --j;
        }
        
        if (extra > 0)
            sum.insert(sum.begin(), '1');
        
        return sum;
    }

private:
    int charToInt(char c) {
        if (c < '0' || c > '1') return -1;
        return (c - '0');
    }
    
    char intToChar(int bit) {
        return ((int)'0' + bit);
    }
};