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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode h(-1, head), *p1 = head, *p2 = &h;
        int val = p1->val, count = 1;
        while(p1){
            if(!p1->next){
                if(count == 1){
                    p2->next = p1;
                }else{
                    p2->next = 0;
                }
                break;
            }else if(p1->next->val != val){
                if(count == 1){
                    p2->next = p1;
                    p2 = p2->next;
                }
                val = p1->next->val;
                count = 1;
            }else{
                count++;
            }
            p1 = p1->next;
        }
        return h.next;
    }
};
