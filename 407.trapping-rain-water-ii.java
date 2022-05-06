/*
 * @lc app=leetcode id=407 lang=java
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
class Solution {
    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length;
        int n = heightMap[0].length;
        PriorityQueue<Pair<Integer, Integer>> que = new PriorityQueue<Pair<Integer, Integer>>(m * n, (i,j)->{return i.getKey() - j.getKey();});
        boolean visited[][] = new boolean[m][n];
        for(int i = 0; i < m; i++) Arrays.fill(visited[i], false);
        for(int i = 0; i < m; i++){
            que.add(new Pair<Integer, Integer>(heightMap[i][0], i * n));
            que.add(new Pair<Integer, Integer>(heightMap[i][n - 1], i * n + n - 1));
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for(int j = 1; j < n - 1; j++){
            que.add(new Pair<Integer, Integer>(heightMap[0][j], j));
            que.add(new Pair<Integer, Integer>(heightMap[m - 1][j], (m - 1) * n + j));
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }
        
        //System.out.println(que.toString());
        int dirs[][] = {{0, 1},{0, -1},{1, 0},{-1, 0}};
        int maxHeight = Integer.MIN_VALUE;
        int res = 0;
        while(!que.isEmpty()){
            var queHead = que.poll();
            int height = queHead.getKey();
            int x = queHead.getValue() / n;
            int y = queHead.getValue() % n;
            maxHeight = Integer.max(maxHeight, height);
            for(int[] dir : dirs){
                int x2 = x + dir[0];
                int y2 = y + dir[1];
                //System.out.print(Integer.toString(x2) + " " + Integer.toString(y2) + ' ');
                if(x2 >= m || x2 < 0 || y2 >= n || y2 < 0 || visited[x2][y2]) continue;
                int newheight = heightMap[x2][y2];
                if(newheight < maxHeight){
                    res += maxHeight - newheight;
                }
                visited[x2][y2] = true;
                que.add(new Pair<Integer, Integer>(newheight, x2 * n + y2));
            }
            //System.out.println(":" + Integer.toString(x) + " " + Integer.toString(y));
        }
        return res;
    }
}
// @lc code=end

