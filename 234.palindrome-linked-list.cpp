/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        int l = 0;
        ListNode *p = head;
        while(p){
            l++;
            p = p->next;
        }
        //cout<<l;
        ListNode* h2;
        p = head;
        for(int i = 0; i < l / 2 - 1; i++){
            p = p->next;
        }
        if(l % 2 == 0){
            h2 = p->next;
            p->next = nullptr;
        }else{
            h2 = p->next->next;
            p->next = nullptr;
        }
        //cout<<head->val<<h2->val;
        head = reverse(head);
        assert(h2 != nullptr);
        cout<<head->val<<h2->val;
        while(head && h2){
            if(head->val != h2->val) return false;
            else{
                head = head->next;
                h2 = h2->next;
            }
        }
        return true;
    }
    ListNode* reverse(ListNode* head){
        if(!head) return head;
        ListNode * p1 = nullptr, *p2 = head, *p3 = head->next;
        while(p2){
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

