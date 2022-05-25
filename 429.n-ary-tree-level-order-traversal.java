/*
 * @lc app=leetcode id=429 lang=java
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(root == null) return res;
        var lastLevel = new ArrayList<Node>();
        var nextLevel = new ArrayList<Node>();
        var rootRes = new ArrayList<Integer>();
        rootRes.add(root.val);
        res.add(rootRes);
        lastLevel.add(root);
        while(!lastLevel.isEmpty()){
            var levelRes = new ArrayList<Integer>();
            for(Node parentNode : lastLevel){
                for(Node node : parentNode.children){
                    levelRes.add(node.val);
                    nextLevel.add(node);
                }
            }
            if(levelRes.size() != 0) res.add(levelRes);
            lastLevel = nextLevel;
            nextLevel = new ArrayList<Node>();
        }
        return res;
    }
}
// @lc code=end

