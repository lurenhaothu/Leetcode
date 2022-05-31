/*
 * @lc app=leetcode id=480 lang=java
 *
 * [480] Sliding Window Median
 */

// @lc code=start
class Node{
    public Node prev = null;
    public Node next = null;
    public long val;
    public Node(long val){
        this.val = val;
    }
}
class ListTree{
    public TreeMap<Long, Pair<Node, Node>> dict = new TreeMap<>();
    public Node head = new Node(Long.MIN_VALUE);
    public Node tail = new Node(Long.MAX_VALUE);
    public Node leftMid = head;
    public Node rightMid = tail;
    public ListTree(){
        head.next = tail;
        tail.prev = head;
        dict.put(Long.MAX_VALUE, new Pair(tail, tail));
        dict.put(Long.MIN_VALUE, new Pair(head, head));
    }
    public double getMid(){
        return ((double) leftMid.val + (double) rightMid.val) / 2;
    }
    public void addNum(long num){
        if(dict.containsKey(num)){
            var pair = dict.get(num);
            var node1 = pair.getKey();
            var node2 = pair.getValue();
            var newNode = new Node(num);
            addNode(newNode, node2);
            dict.put(num, new Pair(node1, newNode));
        }else{
            long key = dict.lowerKey(num);
            var node2 = dict.get(key).getValue();
            var newNode = new Node(num);
            addNode(newNode, node2);
            dict.put(num, new Pair(newNode, newNode));
        }
    }
    public void delNum(long num){
        var pair = dict.get(num);
        var node1 = pair.getKey();
        var node2 = pair.getValue();
        if(node2 == node1){
            delNode(node1);
            dict.remove(num);
        }else{
            var prevNode = node2.prev;
            delNode(node2);
            dict.put(num, new Pair(node1, prevNode));
        }
    }
    public void addNode(Node node, Node prev){
        node.prev = prev;
        node.next = prev.next;
        prev.next = node;
        node.next.prev = node;
        long key = prev.val;
        if(key < leftMid.val){
            if(leftMid == rightMid) leftMid = leftMid.prev;
            else rightMid = rightMid.prev;
        }else if(key >= rightMid.val){
            if(leftMid == rightMid) rightMid = rightMid.next;
            else leftMid = leftMid.next;
        }else{
            leftMid = leftMid.next;
            rightMid = rightMid.prev;
        }
    }
    public void delNode(Node node){
        node.next.prev = node.prev;
        node.prev.next = node.next;
        if(leftMid == rightMid){
            if(leftMid == node){
                leftMid = node.prev;
                rightMid = node.next;
            }else if(node.val < leftMid.val){
                rightMid = rightMid.next;
            }else{
                leftMid = leftMid.prev;
            }
        }else{
            if(leftMid == node){
                leftMid = rightMid;
            }else if(rightMid == node){
                rightMid = leftMid;
            }else if(node.val < leftMid.val){
                leftMid = leftMid.next;
            }else{
                rightMid = rightMid.prev;
            }
        }
    }
}
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        ListTree tree = new ListTree();
        for(int i = 0; i < k; i++){
            tree.addNum((long)nums[i]);
        }
        int n = nums.length;
        double[] res = new double[n - k + 1];
        res[0] = tree.getMid();
        for(int i = k; i < n; i++){
            tree.addNum((long)nums[i]);
            tree.delNum((long)nums[i - k]);
            res[i - k + 1] = tree.getMid();
        }
        return res;
    }
}
// @lc code=end

