class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int offset = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i-1] == A[i])
                ++offset;
            else {
                if (offset > 0)
                    A[i-offset] = A[i];
            }
        }
        
        return (n-offset);
    }
};