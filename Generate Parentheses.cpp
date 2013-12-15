class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        generator(ret, "", n, n);
        
        return ret;
    }
    
    void generator(vector<string>& ret, string result, int left, int right) {
        if (right == 0) {
            ret.push_back(result);
            return;
        }
        
        if (left == right) {
            generator(ret, result+"(", left-1, right);
            return;
        }
        
        if (left > 0)
            generator(ret, result+"(", left-1, right);
        generator(ret, result+")", left, right-1);
        
    }
    
};