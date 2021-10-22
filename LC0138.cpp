/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> dic;
        Node *root = new Node(head->val);
        Node *pr = root, *prOrigin = head;
        dic[head] = root;
        dic[nullptr] = nullptr;
        while(pr){
            if(dic.find(prOrigin->next) == dic.end()){
                pr->next = new Node(prOrigin->next->val);
                dic[prOrigin->next] = pr->next;
            }else{
                pr->next = dic[prOrigin->next];
            }
            if(dic.find(prOrigin->random) == dic.end()){
                pr->random = new Node(prOrigin->random->val);
                dic[prOrigin->random] = pr->random;
            }else{
                pr->random = dic[prOrigin->random];
            }
            pr = pr->next;
            prOrigin = prOrigin->next;
        }
        return root;
    }
};
