/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 我的解法：依次merge首尾两个list，最后成为一个list
// 注意事项：注意previous项的设置，每次将list2插入到list1前面之后，previous项目应该更新
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = lists.size();
        if (size == 0) return 0;
        if (size == 1) return lists[0];
        
        ListNode *list1 = lists[0];
        ListNode *previous = 0;
        ListNode *list2 = lists[size-1];
        
        while (list1 != 0 && list2 != 0) {
            if (list1->val <= list2->val) {
                previous = list1;
                list1 = list1->next;
            } else {
                ListNode* nextList2 = list2->next;
                if (previous) {
                    previous->next = list2;
                    list2->next = list1;
                } else {
                    lists[0] = list2;
                    list2->next = list1;
                }
                previous = list2;
                list2 = nextList2;
            }
        }
        
        if (list2) {
            if (previous)
                previous->next = list2;
            else
                lists[0] = list2;
        }
        
        lists.pop_back();
        return mergeKLists(lists);
        
    }
};