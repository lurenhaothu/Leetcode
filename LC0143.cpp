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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *p1 = head, *p2 = head;
        while(p2->next && p2->next->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if(p1 == p2) return;
        else if(p1->next == p2 && !p2->next){
            p1->next = nullptr;
            p2->next = p1;
            head->next = p2;
            return;
        }
        //head->next = p1;
        //return;
        ListNode *p3 = p1->next, *p4;
        p1->next = nullptr;
        p1 = p3;
        p3 = p1->next->next;
        p4 = p1->next;
        p1->next = nullptr;
        while(p4){
            p4->next = p1;
            if(!p3) break;
            p1 = p4;
            p4 = p3;
            p3 = p3->next;
        }
        //head->next = p4;
        //return;
        p1 = p4;
        p2 = head->next;
        p3 = p1;
        p4 = head;
        while(1){
            p4->next = p3;
            p4 = p2;
            if(!p2) break;
            p2 = p3->next;
            p3->next = p4;
            p3 = p2;
            if(!p2) break;
            p2 = p4->next;
        }
        return;
    }
};
