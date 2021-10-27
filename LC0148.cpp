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
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode *p1 = head, *p2 = head, *p3;
        while(p2->next && p2->next->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p3 = p1->next;
        p1->next = nullptr;
        p1 = sortList(head);
        p2 = sortList(p3);
        ListNode *vh = new ListNode(0);
        p3 = vh;
        while(p1 || p2){
            if(!p1){
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }else if(!p2){
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }else{
                if(p1->val < p2->val){
                    p3->next = p1;
                    p1 = p1->next;
                    p3 = p3->next;
                }else{
                    p3->next = p2;
                    p2 = p2->next;
                    p3 = p3->next;
                }
            }
        }
        p3->next = nullptr;
        return vh->next;
    }
};
