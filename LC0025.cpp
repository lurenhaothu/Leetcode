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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode pre(0, head), *h = &pre;
        vector<ListNode*> p(k + 1, 0);
        p[0] = h;
        do{
            for(int i = 1; i < k + 1; i++){
                if(p[i - 1]){
                    p[i] = p[i - 1]->next;
                }else{
                    return h->next;
                }
                
            }
            if(!p[k]) return h->next;
            p[0]->next = p[k];
            p[1]->next = p[k]->next;
            for(int i = k; i > 1; i--){
                p[i]->next = p[i - 1];
            }
            p[0] = p[1];
        }while(p[0]->next);
        return h->next;
    }
};
