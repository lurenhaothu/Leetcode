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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *cur, *p, *q;
        if(!l1 && !l2) return l1;
        else if(!l1) return l2;
        else if(!l2) return l1;
        if(l1->val > l2->val){
            head = l2;
            p = l1;
            q = l2->next;
        }else{
            head = l1;
            p = l1->next;
            q = l2;
        }
        cur = head;
        int a, b;
        while(p||q){
            if(p){ 
                a = p->val;
            }else{
                a = 101;
            }
            if(q){
                b = q->val;
            }else{
                b = 101;
            }
            if(a<b){
                cur->next = p;
                cur = p;
                p = p->next;
            }else{
                cur->next = q;
                cur = q;
                q = q->next;
            }
        }
        return head;
    }
};
