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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return 0;
        vector<vector<ListNode*>> res;
        res.push_back(lists);
        while(res[res.size() - 1].size() > 1){
            int n = res[res.size() - 1].size();
            int t = res.size();
            res.push_back(vector<ListNode*>{});
            for(int i = 0; i < n; i = i + 2){
                //merge res[t-1][i] andres[t-1][i+1]
                if(i + 1 == n) res[t].push_back(res[t-1][i]);
                else{
                    if(!res[t-1][i] && !res[t-1][i + 1]) {
                        res[t].push_back(0);
                        continue;
                    }else if(!res[t-1][i]){
                        res[t].push_back(res[t-1][i + 1]);
                        continue;
                    }else if(!res[t-1][i + 1]){
                        res[t].push_back(res[t-1][i]);
                        continue;
                    }
                    ListNode *head, *cur, *p, *q;
                    if(res[t - 1][i]->val < res[t - 1][i + 1]->val){
                        head = res[t - 1][i];
                        cur = head;
                        p = cur->next;
                        q = res[t - 1][i + 1];
                    }else{
                        head = res[t - 1][i + 1];
                        cur = head;
                        p = res[t - 1][i];
                        q = cur->next;
                    }
                    while(p||q){
                        if(!p){
                            cur->next = q;
                            cur = q;
                            q = q->next;
                        }else if(!q){
                            cur->next = p;
                            cur = p;
                            p = p->next;
                        }else{
                            if(p->val < q->val){
                                cur->next = p;
                                cur = p;
                                p = p->next;
                            }else{
                                cur->next = q;
                                cur = q;
                                q = q->next;
                            }
                        }
                    }
                    res[t].push_back(head);
                }
            }
        }
        return res[res.size() - 1][0];
    }
};
