/*
Problem: Substring with Concatenation of All Words 
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Date: 08/09/2014
Author: Yunping, qufang83@gmail.com
Difficulty: ***^
Review: ***

Note: Not as difficult as it seems. Use two hash tables.
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (S.empty() || L.empty()) return ret;
        
        int len = S.length();
        int N = L.size();
        int K = L[0].length();
        
        unordered_map<string, int> target;
        for (int i = 0; i < N; ++i)
            ++target[L[i]];
        
        for (int i = 0; i <= len - N*K; ++i) {
            unordered_map<string, int> found;
            int j = 0;
            for (; j < N; ++j) {
                string s = S.substr(i + j*K, K);
                auto it = target.find(s);
                if (it == target.end())
                    break;
                if (it->second == found[s])
                    break;
                ++found[s];
            }
            
            if (j == N)
                ret.push_back(i);
        }
        
        return ret;
    }
};