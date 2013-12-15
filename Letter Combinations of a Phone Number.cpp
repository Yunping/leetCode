class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        std::vector<char> result;
        letterCats(digits.c_str(), ret, result);
        
        return ret;
    }
    
    void letterCats(const char* digits, vector<string>& ret, std::vector<char>& result) {
        if (*digits == '\0') {
            ret.push_back(stackToString(result));
            //result.pop();
            return;
        }
        
        string letters = mapToLetters(digits[0]);
        int len = letters.length();
        for (int i = 0; i < len; ++i) {
            result.push_back(letters[i]);
            letterCats(digits + 1, ret, result);
            result.pop_back();
        }
    }
    
    string mapToLetters(char digit) {
        switch (digit) {
            case '1':
                return "";
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
            case '0':
                return " ";
            default:
                return "";
        }
    }
    
    string stackToString(std::vector<char>& s) {
        string ret(s.begin(), s.end());
        return ret;
    }
};