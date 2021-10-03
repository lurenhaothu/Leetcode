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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        else if(!head->next) return head;
        //else if(!head->next->next) return head;
        if(k == 0) return head;
        ListNode *h = head, *t = 0;
        //if(k == 1) t = head;
        int length = 1;
        while(h->next){
            //if(k == length) t = h;
            h = h->next;
            length++;
        }
        //cout<<length;
        h->next = head;
        if(k % length == 0){
            h->next = 0;
            return head;
        }
        t = head;
        for(int i = 1; i < length - k % length; i++){
            t = t->next;
        }
        ListNode *tt = t;
        t = t->next;
        tt->next = 0;
        return t;
    }
};
