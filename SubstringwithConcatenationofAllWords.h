/*
Problem: Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/22/2015
Difficulty: ***
Review: ***
Solution: hash

*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if (s.empty() || words.empty()) return ret;
        
        unordered_map<string, int> words_count;
        for (string w : words)
            ++words_count[w];
        
        int len = s.length();
        int N = words.size();
        int K = words[0].length();
        for (int i = 0; i <= len - N*K; ++i) {
            unordered_map<string, int> found;
            int j = 0;
            for (j = 0; j < N; ++j) {
                string w = s.substr(i+K*j, K);
                auto it = words_count.find(w);
                if (it == words_count.end())
                    break;
                if (found[w] == words_count[w])
                    break;
                ++found[w];
            }
            if (j == N)
                ret.push_back(i);
        }
        
        return ret;
    }
};