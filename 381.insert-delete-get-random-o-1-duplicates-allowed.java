/*
 * @lc app=leetcode id=381 lang=java
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
class RandomizedCollection {
    
    private HashMap<Integer, HashSet<Integer>> map;
    private ArrayList<Integer> list;

    public RandomizedCollection() {
        map = new HashMap<>();
        list = new ArrayList<>();
    }
    
    public boolean insert(int val) {
        if(map.containsKey(val)){
            list.add(val);
            map.get(val).add(list.size() - 1);
            return false;
        }else{
            list.add(val);
            map.put(val, new HashSet<Integer>());
            map.get(val).add(list.size() - 1);
            return true;
        }
    }
    
    public boolean remove(int val) {
        if(!map.containsKey(val)) return false;
        var indexes = map.get(val);
        int listSize = list.size();
        if(indexes.contains(listSize - 1)){
            indexes.remove(listSize -1);
            if(indexes.isEmpty()) map.remove(val);
            list.remove(listSize - 1);
            return true;
        }else{
            var itr = indexes.iterator();
            int index = itr.next();
            itr.remove();
            if(indexes.isEmpty()) map.remove(val);
            int lastVal = list.get(listSize - 1);
            map.get(lastVal).remove(listSize - 1);
            map.get(lastVal).add(index);
            list.set(index, lastVal);
            list.remove(list.size() - 1);
            return true;
        }
    }
    
    public int getRandom() {
        int RandIndex = (int)(Math.random() * list.size());
        return list.get(RandIndex);
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
// @lc code=end

