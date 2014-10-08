/*
Problem: Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/08/2014
Difficulty: **
Review: **
Solution: (My Own)
    First all nodes without considering 'next' or 'random' pointers. 
    Using a hash map from old node to new node.
    Second, process all pointers in the new list by using the map.
相关题目：
    《剑指offer》：复杂链表的拷贝

*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return 0;
        
        // copy nodes
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode *p = head;
        while (p) {
            RandomListNode *newNode = new RandomListNode(p->label);
            map[p] = newNode;
            p = p->next;
        }
        
        // process 'next' and 'random' pointers.
        RandomListNode* clone = 0;
        for (p = head; p; p = p->next) {
            clone = map[p];
            clone->next = p->next ? map[p->next] : 0;
            clone->random = p->random ? map[p->random] : 0;
        }
        
        return map[head];
    }
};