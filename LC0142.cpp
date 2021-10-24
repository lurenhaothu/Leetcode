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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        if(!head->next) return nullptr;
        if(!head->next->next) return nullptr;
        ListNode *p1 = head->next, *p2 = head->next->next, *p3 = head, *p4 = head;
        while(p2 != p1){
            if(!p2) return nullptr;
            if(!p2->next) return nullptr;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p2->next;
        p3 = p3->next;
        while(p2 != p1){
            p2 = p2->next;
            p3 = p3->next;
        }
        while(p3 != p4){
            p3 = p3->next;
            p4 = p4->next;
        }
        return p4;
    }
};
