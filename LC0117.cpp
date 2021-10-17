/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        connect(root->left);
        connect(root->right);
        Node *pr1 = root->left, *pr2 = root->right, *l1, *l2;
        while(pr1 && pr2){
            cout<<pr1->val<<pr2->val<<endl;
            l1 = pr1;
            l2 = pr2;
            while(l1->next) l1 = l1->next;
            while(pr1 && !pr1->left && !pr1->right) pr1 = pr1->next;
            if(pr1) pr1 = pr1->left ? pr1->left : pr1->right;
            while(pr2 && !pr2->left && !pr2->right) pr2 = pr2->next;
            if(pr2) pr2 = pr2->left ? pr2->left : pr2->right;
            l1->next = l2;
        }
        return root;
    }
};
