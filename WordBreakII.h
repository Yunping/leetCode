/*
Problem: Word Break II
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/11/2014
Difficulty: ***^
Review: ****
Solution: (My Own)
    1. Use the same method as question "Word Break" to check if s[0~i] can be broken
    2. Use DFS to generate all pathes (Like find all pathes in a tree from root to leaf)
*/
class Solution {
private:
    struct DPRecords {
        // if s[0, i-1] can be broken
        bool valid;
        // All index j before i which makes: d[j].valid = true, and s[j, i-1] is in the dict.
        list<int> prevs;
        DPRecords(bool v = false) : valid(v) {}
    };
    
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<DPRecords> d(n+1, DPRecords(false));
        d[0].valid = true;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i-j);
                if (d[j].valid && dict.find(sub) != dict.end()) {
                    d[i].valid = true;
                    d[i].prevs.push_back(j);
                }
            }
        }
        
        vector<string> ret;
        vector<string> temp;
        generateResults(s, n, d, temp, ret);
        
        return ret;
    }
    
private:
    // generate final results using DFS
    void generateResults(string& s, int len, vector<DPRecords>& d, vector<string>& words, vector<string> &ret) {
        if (!d[len].valid) return;
        if (len == 0) {
            if (!words.empty()) {
                int sz = words.size();
                string result = words.back();
                for (int i = sz-2; i >= 0; --i) {
                    result += " ";
                    result += words[i];
                }
                
                ret.push_back(result);
            }
            
            return;
        }
        
        // check each valid prevs of d[len].
        for (int j:d[len].prevs) {
            words.push_back(s.substr(j, len-j));
            generateResults(s, j, d, words, ret);
            words.pop_back();
        }
    }
};