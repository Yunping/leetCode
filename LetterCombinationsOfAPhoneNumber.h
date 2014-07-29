/*
Problem: Letter Combinations of a Phone Number 
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.


Date: 07/29/2014
Difficulty: **
Review: **
Note: 典型的递归题目。
对于每个数字对应的字母串，从字母串中依次取出一个字符作为结果，然后递归地计算下一个数字
*/

class Solution {
public:
    string digitToLetters(int digit) {
    	string ret;
    	switch(digit) {
    	case 2:
    		ret = "abc";
    		break;
    	case 3:
    		ret = "def";
    		break;
    	case 4:
    		ret = "ghi";
    		break;
    	case 5:
    		ret = "jkl";
    		break;
    	case 6:
    		ret = "mno";
    		break;
    	case 7:
    		ret = "pqrs";
    		break;
    	case 8:
    		ret = "tuv";
    		break;
    	case 9:
    		ret = "wxyz";
    		break;
    	case 0:
    		ret = " ";
    	default:
    	    break;
    	}
    
    	return ret;
    }

    void letterCombinations(string digits, int cur_i, string& result, vector<string>& ret) {
    	size_t len = digits.length();
    	if (cur_i == len) {
    		ret.push_back(result);
    		return;
    	}
    
    	string letters = digitToLetters(digits[cur_i] - '0');
    	for (int i = 0; i < letters.length(); ++i) {
    		result.push_back(letters[i]);
    		letterCombinations(digits, cur_i+1, result, ret);
    		result.pop_back();
    	}
    }
    
    vector<string> letterCombinations(string digits) {
    	vector<string> ret;
    	string result;
    	letterCombinations(digits, 0, result, ret);
    
    	return ret;
    }
};