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
    ListNode *h, *t;
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return nullptr;
        t = new ListNode(10000);
        h = new ListNode(-10000, t);
        ListNode *p1 = head, *p2 = head->next;
        while(p1){
            update(p1);
            if(p2){
                p1 = p2;
                p2 = p2->next;
            }else{
                break;
            }
        }
        p1 = h;
        while(p1->next->next) p1 = p1->next;
        p1->next = nullptr;
        return h->next;
    }
    
    void update(ListNode *insert){
        ListNode *pr = h;
        while(insert->val > pr->next->val){
            pr = pr->next;
        }
        insert->next = pr->next;
        pr->next = insert;
        return;
    }
};
