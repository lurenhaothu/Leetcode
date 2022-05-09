/*
 * @lc app=leetcode id=417 lang=java
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int m = heights.length;
        int n = heights[0].length;
        HashSet<Integer> PO = new HashSet<Integer>();
        boolean visited[][] = new boolean[m][n];
        ArrayDeque<Integer> que = new ArrayDeque<Integer>();
        for(int i = 0; i < m; i++) que.add(i * n);
        for(int i = 1; i < n; i++) que.add(i);
        int[][] dir = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!que.isEmpty()){
            int num = que.poll();
            int i = num / n;
            int j = num % n;
            visited[i][j] = true;
            PO.add(i * n + j);
            for(int[] d : dir){
                int ii = i + d[0];
                int jj = j + d[1];
                if(ii < 0 || ii >= m || jj < 0 || jj >= n || visited[ii][jj] || heights[ii][jj] < heights[i][j]) continue;
                que.addLast(ii * n + jj);
            }
        }
        
        //System.out.println(PO.toString());
        
        HashSet<Integer> AO = new HashSet<Integer>();
        visited = new boolean[m][n];
        que = new ArrayDeque<Integer>();
        for(int i = 0; i < m; i++) que.add(i * n + n - 1);
        for(int i = 0; i < n - 1; i++) que.add((m - 1) * n + i);
        while(!que.isEmpty()){
            int num = que.poll();
            int i = num / n;
            int j = num % n;
            visited[i][j] = true;
            AO.add(i * n + j);
            for(int[] d : dir){
                int ii = i + d[0];
                int jj = j + d[1];
                if(ii < 0 || ii >= m || jj < 0 || jj >= n || visited[ii][jj] || heights[ii][jj] < heights[i][j]) continue;
                que.addLast(ii * n + jj);
            }
        }
        ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
        for(int num : PO){
            if(AO.contains(num)){
                res.add(Arrays.asList(num / n, num % n));
            }
        }
        return res;
    }
}
// @lc code=end

