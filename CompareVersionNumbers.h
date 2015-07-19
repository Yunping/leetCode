/*
Problem: Compare Version Numbers

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37

=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 07/19/2015
Difficulty: **
Review: **
Solution:
*/
class Solution {
private:
    // seperate string by '.'
    vector<string> versionToNumbers(string version) {
        char seperator = '.';
        vector<string> numbers;
        size_t length = version.length();
        size_t begin = 0;
        while (begin < length) {
            size_t pos = version.find_first_of(seperator, begin);
            if (pos == string::npos) pos = length;
            numbers.push_back(version.substr(begin, pos - begin));
            begin = pos + 1;
        }
        
        return numbers;
    }
    
    // compare number of string
    int stringCompare(string str1, string str2) {
        int zeroCount1 = str1.find_first_not_of('0');
        int zeroCount2 = str2.find_first_not_of('0');
        if (zeroCount1 == string::npos) zeroCount1 = str1.length();
        if (zeroCount2 == string::npos) zeroCount2 = str2.length();
        
        // trim beginning zeros
        str1 = str1.substr(zeroCount1);
        str2 = str2.substr(zeroCount2);
        int len1 = str1.length();
        int len2 = str2.length();
        if (len1 > len2) return 1;
        if (len1 < len2) return -1;
        for (int i = 0; i < len1; ++i) {
            if (str1[i] == str2[i])
                continue;
            if (str1[i] > str2[i])
                return 1;
            else
                return -1;
        }
        return 0;
    }
    
public:
    int compareVersion(string version1, string version2) {
        vector<string> nums1 = versionToNumbers(version1);
        vector<string> nums2 = versionToNumbers(version2);
        int size1 = nums1.size();
        int size2 = nums2.size();
        for (int i = 0; i < std::min(size1, size2); ++i) {
            int cmp = stringCompare(nums1[i], nums2[i]);
            if (cmp != 0) return cmp;
        }
        
        // if size1 != size2, continue compare the remainning numbers with "0"
        if (size1 != size2) {
            for (int i = std::min(size1, size2); i < std::max(size1, size2); ++i) {
                int cmp = size1 > size2 ? stringCompare(nums1[i], "0") : stringCompare("0", nums2[i]);
                if (cmp != 0) return cmp;
            }
            return 0;
        }
        
        return 0;
    }
};