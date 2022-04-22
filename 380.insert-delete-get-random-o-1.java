/*
 * @lc app=leetcode id=380 lang=java
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
    
    private HashMap<Integer, Integer> map;
    private ArrayList<Integer> list;

    public RandomizedSet() {
        map = new HashMap<>();
        list = new ArrayList<>();
    }
    
    public boolean insert(int val) {
        if(map.containsKey(val)) return false;
        list.add(val);
        map.put(val, list.size() - 1);
        return true;
    }
    
    public boolean remove(int val) {
        if(!map.containsKey(val)) return false;
        int index = map.get(val);
        if(index == list.size() - 1){
            map.remove(val);
            list.remove(index);
            return true;
        }else{
            int lastVal = list.get(list.size() - 1);
            map.put(lastVal, index);
            map.remove(val);
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
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
// @lc code=end

