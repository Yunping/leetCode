/*
Problem: Word Ladder
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

========================================================================

Author: Yunping, qufang83@gmail.com
Date: 11/12/2014
Difficulty: ****
Review: ****
Solution:
    BFS
    *NOTE*:
        1. Don't try to create a graph from the dict because the dict may be very huge.
        2. Transform the word then, if the transformed word equals end, done; otherwise, 
           query from the dict to see if the transformed word is an adj of word.
*/
class Solution {
    struct Node {
        string value;
        int dist;
        Node(string& v, int d) : value(v), dist(d) {}
    };
    
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<Node> q;
        q.push(Node(start, 1));
        
        while (!q.empty()) {
            Node word = q.front();
            q.pop();
            
            string str = word.value;
            int len = str.size();
            for (int i = 0; i < len; ++i) {
                char temp = str[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (str[i] == c) continue;
                    str[i] = c;
                    if (str == end) {
                        return (word.dist + 1);
                    }
                    
                    if (dict.find(str) != dict.end()) {
                        q.push(Node(str, word.dist+1));
                        dict.erase(str); // erase it from the dict, no need to use a 'marked' array.
                    }
                }
                
                str[i] = temp;
            }
        }
        
        return 0;
    }
};