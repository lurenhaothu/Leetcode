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
        ListNode *h, *p, *q, *cur;
        h = head;
        cur = h;
        do{
            if(cur){
                p = cur->next;
                cur = p;
            }else{
                break;
            }
            if(cur){
                q = cur->next;
                cur = q;
            }else{
                break;
            }
            if(cur){
                cur = cur->next;
            }
        }while(1);
        return h;
    }
};
