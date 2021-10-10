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
    ListNode* partition(ListNode* head, int x) {
        ListNode less(0), greater(0), *pr = head, *prl = &less, *prg = &greater;
        while(pr){
            if(pr->val < x){
                prl->next = pr;
                pr = pr->next;
                prl = prl->next;
            }else{
                prg->next = pr;
                pr = pr->next;
                prg = prg->next;
            }
        }
        prl->next = greater.next;
        prg->next = 0;
        return less.next;
    }
};
