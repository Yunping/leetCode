class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret;
        int count = strs.size();        
        if (count > 0) {
            int len1 = strs[0].length();
            for (int i = 0; i < len1; ++i) {
                bool equal = true;
                for (int j = 1; j < count; ++j) {
                    if (i < strs[j].length()) {
                        if (strs[0][i] != strs[j][i]) {
                            equal = false;
                            break;
                        }
                    } else {
                        equal = false;
                        break;
                    }
                }
                if (equal)
                    ret.push_back(strs[0][i]);
                else
                    break;
            }
        }
        
        return ret;
    }
};