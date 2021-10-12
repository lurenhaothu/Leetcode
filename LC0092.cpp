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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode h(0, head);
        ListNode *left_1, *right_1, *p1 = &h, *p2, *p3;
        for(int i = 0; i <= right; i++){
            if(i == left - 1) left_1 = p1;
            else if(i == right) right_1 = p1;
            p1 = p1->next;
        }
        p1 = left_1->next;
        p2 = p1->next;
        p3 = p2->next;
        left_1->next = right_1;
        p1->next = right_1->next;
        while(p1 != right_1){
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if(p3) p3 = p3->next;
            else break;
        }
        return h.next;
    }
};
