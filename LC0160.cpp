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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode *ha = headA, *hb = headB;
        int la = 1, lb = 1;
        while(ha->next) ha = ha->next, la++;
        while(hb->next) hb = hb->next, lb++;
        if(ha != hb) return nullptr;
        ha = headA;
        hb = headB;
        if(la >= lb){
            for(int i = lb; i < la; i++){
                ha = ha->next;
            }  
        }else{
            for(int i = la; i < lb; i++){
                hb = hb->next;
            } 
        }
        while(ha != hb) ha = ha->next, hb = hb->next;
        return ha;
    }
};
