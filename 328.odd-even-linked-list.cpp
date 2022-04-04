/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* odd = new ListNode(0), *even = new ListNode(0);
        ListNode* ptrodd = odd, *ptreven = even;
        ListNode* ptr = head;
        while(ptr){
            ptrodd->next = ptr;
            ptr = ptr->next;
            ptrodd = ptrodd->next;
            ptrodd->next = nullptr;
            if(!ptr) break;
            else{
                ptreven->next = ptr;
                ptr = ptr->next;
                ptreven = ptreven->next;
                ptreven->next = nullptr;
            }
        }
        ptrodd->next = even->next;
        return odd->next;
    }
};
// @lc code=end

