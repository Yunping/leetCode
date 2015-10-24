/*
Problem: Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 07/29/2014
Refactor: 10/24/2015
Difficulty: **
Review: *^
Solution: DFS
*/
class Solution {
private:
    string digitToLetters(char digit) {
        switch (digit) {
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
            default:
                return "";
        }
    }

    void letterCombinations(string &digits, int index, string &result, vector<string> &ret) {
        if (index  == digits.size()) {
            ret.push_back(result);
            return;
        }
        
        string letters = digitToLetters(digits[index]);
        for (char letter : letters) {
            result.push_back(letter);
            letterCombinations(digits, index+1, result, ret);
            result.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (!digits.empty()) {
            string result;
            letterCombinations(digits, 0, result, ret);
        }
        return ret;
    }
};