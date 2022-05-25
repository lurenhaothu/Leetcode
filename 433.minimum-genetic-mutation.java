/*
 * @lc app=leetcode id=433 lang=java
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
    public int minMutation(String start, String end, String[] bank) {
        if(end.equals(start)) return 0;
        int n = bank.length;
        boolean graph[][] = new boolean[n + 1][n];
        int endIndex = -1;
        for(int i = 0; i < n; i++){
            if(end.equals(bank[i])) endIndex = i; 
        }
        if(endIndex == -1) return -1;
        for(int i = 0; i < n; i++){
            if(dif(start, bank[i]) == 1) graph[0][i] = true;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dif(bank[j], bank[i]) == 1) graph[i + 1][j] = true;
            }
        }
        ArrayDeque<Integer> que = new ArrayDeque<Integer>();
        for(int i = 0; i < n; i++){
            if(graph[0][i]) que.add(i);
        }
        boolean visited[] = new boolean[n];
        int distance = 0;
        //System.out.println(Arrays.deepToString(graph));
        while(!que.isEmpty()){
            int m = que.size();
            distance++;
            for(int j = 0; j < m; j++){
                //System.out.println(que.toString());
                int p = que.poll();
                if(p == endIndex) return distance;
                visited[p] = true;
                for(int i = 0; i < n; i++){
                    if(graph[p + 1][i] && !visited[i]) que.add(i);
                }
            }
        }
        return -1;
    }
    private int dif(String a, String b){
        int dif = 0;
        for(int i = 0; i < 8; i++){
            if(a.charAt(i) != b.charAt(i)) dif++;
        }
        return dif;
    }
}
// @lc code=end

