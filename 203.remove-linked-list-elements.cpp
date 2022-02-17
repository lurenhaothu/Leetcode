/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* h = new ListNode(0, head);
        ListNode* pr = h;
        while(pr->next){
            //cout<<1<<endl;
            if(pr->next->val == val){
                pr->next = pr->next->next;
            }else pr = pr->next;
        }
        pr = h->next;
        delete h;
        return pr;
    }
};
// @lc code=end

