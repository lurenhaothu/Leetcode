/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *pr = head;
        while(pr){
            if(pr->val == 2e5) return true;
            else{
                pr->val = 2e5;
                pr = pr->next;
            }
        }
        return false;
    }
};
