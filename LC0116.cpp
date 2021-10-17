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
        if(!root->left) return root;
        connect(root->left);
        connect(root->right);
        Node *pr1 = root->left, *pr2 = root->right;
        while(pr1){
            pr1->next = pr2;
            pr1 = pr1->right;
            pr2 = pr2->left;
        }
        return root;
    }
};
