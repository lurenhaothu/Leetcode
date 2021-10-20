/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node *root = new Node(node->val);
        vector<Node*> dic(101, nullptr);
        queue<Node*> qOrigin, qClone;
        qOrigin.push(node);
        qClone.push(root);
        dic[root->val] = root;
        while(!qOrigin.empty()){
            Node *nodeOrigin = qOrigin.front();
            Node *nodeClone = qClone.front();
            qOrigin.pop();
            qClone.pop();
            for(auto p : nodeOrigin->neighbors){
                if(dic[p->val]) nodeClone->neighbors.push_back(dic[p->val]);
                else{
                    nodeClone->neighbors.push_back(new Node(p->val));
                    dic[p->val] = nodeClone->neighbors.back();
                    qOrigin.push(p);
                    qClone.push(dic[p->val]);
                }
            }
        }
        return root;
    }
};
