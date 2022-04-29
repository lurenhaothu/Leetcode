/*
 * @lc app=leetcode id=399 lang=java
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        HashMap<String, List<Pair<String, Double>>> map = new HashMap<>();
        int n = equations.size();
        for(int i = 0; i < n; i++){
            var equation = equations.get(i);
            var value = values[i];
            if(!map.containsKey(equation.get(0))) map.put(equation.get(0), new ArrayList<Pair<String, Double>>());
            if(!map.containsKey(equation.get(1))) map.put(equation.get(1), new ArrayList<Pair<String, Double>>());
            map.get(equation.get(0)).add(new Pair<String, Double>(equation.get(1), value));
            map.get(equation.get(1)).add(new Pair<String, Double>(equation.get(0), 1 / value));
        }
        int m = queries.size();
        double res[] = new double[m];
        for(int i = 0; i < m; i++){
            res[i] = helper(map, queries.get(i));
        }
        return res;
    }
    
    public double helper(HashMap<String, List<Pair<String, Double>>> map, List<String> queries){
        if(!map.containsKey(queries.get(0)) || !map.containsKey(queries.get(1))) return -1.0;
        HashSet<String> candSet = new HashSet<String>(map.keySet());
        ArrayDeque<Pair<String, Double>> q = new ArrayDeque<>();
        q.push(new Pair<String, Double>(queries.get(0), 1.0));
        while(!q.isEmpty()){
            var pair = q.pop();
            if(queries.get(1).equals(pair.getKey())) return pair.getValue();
            candSet.remove(pair.getKey());
            var list = map.get(pair.getKey());
            for(var p : list){
                if(!candSet.contains(p.getKey())) continue;
                q.push(new Pair<String, Double>(p.getKey(), pair.getValue() * p.getValue()));
            }
        }
        return -1.0;
    }
}
// @lc code=end

