/*
 * @lc app=leetcode id=382 lang=java
 *
 * [382] Linked List Random Node
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
    ListNode head;
    ListNode cur;
    int size;

    public Solution(ListNode head) {
        this.head = head;
        this.cur = head;
        size = 0;
        while(cur != null){
            size++;
            cur = cur.next;
        }
        cur = head;
    }
    
    public int getRandom() {
        int step = (int)(Math.random() * (size + 1));
        forward(step);
        return cur.val;
    }
    
    private void forward(int step){
        for(int i = 0; i < step; i++){
            if(cur.next != null){
                cur = cur.next;
            }else{
                cur = head;
            }
        }
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
// @lc code=end

