/*
 * @lc app=leetcode id=430 lang=java
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    public Node flatten(Node head) {
        return helper(head)[0];
    }
    
    private Node[] helper(Node head){
        Node ptr = head;
        Node tail = null;
        while(ptr != null){
            while(ptr != null && ptr.child == null){
                if(ptr.next == null) tail = ptr;
                ptr = ptr.next;
            }
            if(ptr == null) break;
            Node[] childRes = helper(ptr.child);
            childRes[1].next = ptr.next;
            if(childRes[1].next != null)childRes[1].next.prev = childRes[1];
            ptr.next = childRes[0];
            childRes[0].prev = ptr;
            ptr.child = null;
            ptr = childRes[1].next;
            if(childRes[1].next == null) tail = childRes[1];
        }
        return new Node[]{head, tail};
    }
}
// @lc code=end

