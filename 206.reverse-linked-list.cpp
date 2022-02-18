/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        else if(!head->next) return head;
        ListNode *p1 = nullptr, *p2 = head, *p3 = head->next;
        while(1){
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if(p3) p3 = p3->next;
            else break;
        }
        return p1;
    }
};
// @lc code=end

