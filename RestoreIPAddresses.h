/*
Problem: Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/14/2014
Difficulty: **^
Review: ***
Solution: (My Own)
    Back-tracking
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        restoreIpAddrs(s, 0, 4, "", ret);
        
        return ret;
    }
    
private:
    void restoreIpAddrs(string &s, int index, int leftCount, string result, vector<string> &ret) {
        int n = s.size();
        int leftLength = n - index;
        
        if (leftLength == 0 && leftCount == 0) {
            ret.push_back(result.substr(1));
            return;
        }
        
        if (leftLength > leftCount * 3 || leftLength < leftCount) return;
        
        restoreIpAddrs(s, index+1, leftCount-1, result+"."+s.substr(index, 1), ret);
        
        if (leftLength >= 2 && s[index] != '0') {
            restoreIpAddrs(s, index+2, leftCount-1, result+"."+s.substr(index, 2), ret);
            if (leftLength >= 3) {
                int num = atoi(s.substr(index, 3).c_str());
                if (num <= 255)
                    restoreIpAddrs(s, index+3, leftCount-1, result+"."+s.substr(index, 3), ret);
            }
        }
    }
};