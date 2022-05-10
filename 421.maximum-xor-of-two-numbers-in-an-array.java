/*
 * @lc app=leetcode id=421 lang=java
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
class TrieNode{
    public TrieNode[] children = new TrieNode[]{null, null};
    public TrieNode(){}
}

class Solution {
    public int findMaximumXOR(int[] nums) {
        int n = nums.length;
        String[] strNums = new String[n];
        int maxNum = Integer.MIN_VALUE;
        for(int num : nums) maxNum = Integer.max(maxNum, num);
        int length = Integer.toBinaryString(maxNum).length();
        for(int i = 0; i < n; i++){
            strNums[i] = Integer.toBinaryString(nums[i] + (1 << length)).substring(1);
        }
        int res = 0;
        TrieNode root = new TrieNode();
        for(String num : strNums){
            var node = root;
            var xorNode = root;
            int r = 0;
            for(int i = 0; i < length; i++){
                var bit = num.charAt(i) == '1' ? 1 : 0;
                if(node.children[bit] == null)
                    node.children[bit] = new TrieNode();
                node = node.children[bit];
                
                var xbit = bit == 1 ? 0 : 1;
                if(xorNode.children[xbit] == null){
                    r = r << 1;
                    xorNode = xorNode.children[bit];
                }else{
                    r = (r << 1) + 1;
                    xorNode = xorNode.children[xbit];
                }
            }
            res = Integer.max(r, res);
        }
        return res;
    }
}
// @lc code=end

