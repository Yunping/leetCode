class Solution {
public:
	
    map<int, int> mem;
    int **isPalin;
    
    Solution():isPalin(0){}
    
    int minCut(string s) {
        mem.clear();
        initPalinMem(s);
        
        return dp(s, 0);
    }
    
private:
    int dp(string s, int start) {
        if (mem.find(start) != mem.end())
            return mem[start];
		
        size_t len = s.length();
        if (isPalindrome(s, start, len - 1))
            return mem[start] = 0;
        
        int min = len - start - 1;
        for (size_t j = start; j < len - 1; ++j) {
            if (isPalindrome(s, start, j)) {
                int t = dp(s, j + 1) + 1;
                if (t < min)
                    min = t;
            }
        }
        
        mem[start] = min;
        return min;
    }
    
    
    void initPalinMem(string s) {
        size_t len = s.length();
        if (len > 0) {
            if (isPalin != 0) {
                delete []isPalin;
                isPalin = 0;
            }
            isPalin = new int*[len];
            for (int i = 0; i < len; ++i) {
                isPalin[i] = new int[len];
                for (int j = 0; j < len; ++j) {
                    if (i == j)
                        isPalin[i][j] = 1;
                    else
                        isPalin[i][j] = -1;
                }
            }
        }
    }
    
    bool isPalindrome(string s, int m, int n) {
		
		if (isPalin[m][n] != -1)
            return isPalin[m][n];
        
        bool ret = true;
        if (n - m >= 1) {
            if (s[m] == s[n])
                ret = isPalindrome(s, m+1, n-1);
            else
                ret = false;
        }
		
        return isPalin[m][n] = ret;
    }
};