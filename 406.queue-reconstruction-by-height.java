/*
 * @lc app=leetcode id=406 lang=java
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (int[] i, int[] j)->{return (i[0] == j[0]) ? i[1] - j[1] : j[0] - i[0];});
        System.out.print(Arrays.deepToString(people));
        ArrayList<int[]> res = new ArrayList<>();
        for(int i = 0; i < people.length; i++){
            //Integer addRes = new Integer
            res.add(people[i][1], people[i]);
        }
        int[][] resArray = new int[people.length][2];
        for(int i = 0; i < people.length; i++){
            resArray[i] = res.get(i);
        }
        return resArray;
    }
}
// @lc code=end

