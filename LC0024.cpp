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
    ListNode* swapPairs(ListNode* head) {
        ListNode prehead(0, head);
        ListNode *h, *cur, *p, *q;
        h = &prehead;
        cur = h;
        do{
            p = cur->next;
            if(p){
                q = p->next;
                if(q){
                    p->next = q->next;
                    q->next = p;
                    cur->next = q;
                    cur = p;
                }else{
                    break;
                }
            }else{
                break;
            }
        }while(cur);
        return h->next;
    }
};
