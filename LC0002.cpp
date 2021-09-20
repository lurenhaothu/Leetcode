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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, nownode, *pr = &nownode;
        int state1 = 1, state2 = 1, stateadd = 0;
        while(state1 || state2 || stateadd){
            if(state1 && state2){
                int v = p1->val + p2->val + stateadd;
                stateadd = v / 10;
                ListNode newone(v%10);
                pr->next = &newone;
                pr = pr->next;
                if(p1->next){
                    p1 = p1->next;
                    state1 = 1;
                }else{
                    state1 = 0;
                }
                if(p2->next){
                    p2 = p2->next;
                    state2 = 1;
                }else{
                    state2 = 0;
                }
            }else if(state1){
                int v = p1->val + stateadd;
                stateadd = v / 10;
                ListNode newone(v%10);                
                pr->next = &newone;
                pr = pr->next;
                if(p1->next){
                    p1 = p1->next;
                    state1 = 1;
                }else{
                    state1 = 0;
                }
            }else if(state2){
                int v = p2->val + stateadd;
                stateadd = v / 10;
                ListNode newone(v%10); 
                pr->next = &newone;
                pr = pr->next;
                if(p2->next){
                    p2 = p2->next;
                    state2 = 1;
                }else{
                    state2 = 0;
                }
            }else{
                ListNode newone(stateadd);
                stateadd = 0;
                pr->next = &newone;
                pr = pr->next;
            }
        }
        return nownode.next;
        //return NULL;
    }
};
