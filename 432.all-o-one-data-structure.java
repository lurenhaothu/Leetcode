/*
 * @lc app=leetcode id=432 lang=java
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
class StringNode{
    public int count = 0;
    public HashSet<String> content = new HashSet<>();
    public StringNode prev = null;
    public StringNode next = null;
    public StringNode(){}
    public String toString(){
        return "[" + Integer.toString(count) + " : "+ content.toString() + "]";
    }
}

class StringLinkedList{
    public StringNode head = null;
    public StringNode tail = null;
    public StringLinkedList(){
        head = new StringNode();
        tail = new StringNode();
        head.count = Integer.MAX_VALUE;
        tail.count = Integer.MIN_VALUE;
        head.next = tail;
        tail.prev = head;
    }
    public StringNode addNode(String key, int count, StringNode node){
        if(count > node.count){
            var prevNode = node.prev;
            if(prevNode.count == count){
                prevNode.content.add(key);
                return prevNode;
            }else{
                var newNode = new StringNode();
                newNode.count = count;
                newNode.content.add(key);
                prevNode.next = newNode;
                newNode.prev = prevNode;
                node.prev = newNode;
                newNode.next = node;
                return newNode;
            }
        }else{
            var nextNode = node.next;
            if(nextNode.count == count){
                nextNode.content.add(key);
                return nextNode;
            }else{
                var newNode = new StringNode();
                newNode.count = count;
                newNode.content.add(key);
                nextNode.prev = newNode;
                newNode.next = nextNode;
                node.next = newNode;
                newNode.prev = node;
                return newNode;
            }
        }
    }
    
    public void removeNode(String key, StringNode node){
        node.content.remove(key);
        if(node.content.isEmpty()){
            var prevNode = node.prev;
            var nextNode = node.next;
            prevNode.next = nextNode;
            nextNode.prev = prevNode;
        }
    }
    
    public StringNode inc(String key, StringNode node){
        int count = node.count;
        var res = addNode(key, count + 1, node);
        removeNode(key, node);
        return res;
    }
    
    public StringNode dec(String key, StringNode node){
        int count = node.count;
        StringNode res;
        if(count == 1) res = null;
        else res = addNode(key, count - 1, node);
        removeNode(key, node);
        return res;
    }
    
    public String toString(){
        StringBuilder s = new StringBuilder();
        var ptr = head;
        while(ptr != null){
            s.append(ptr.toString());
            ptr = ptr.next;
        }
        return s.toString();
    }
}

class AllOne {
    
    StringLinkedList stringLinkedList = new StringLinkedList();
    HashMap<String, StringNode> map = new HashMap<>();
    
    public AllOne() {
    }
    
    public void inc(String key) {
        if(!map.containsKey(key)){
            StringNode node = stringLinkedList.addNode(key, 1, stringLinkedList.tail);
            map.put(key, node);
        }else{
            StringNode node = map.get(key);
            node = stringLinkedList.inc(key, node);
            map.put(key, node);
        }
        //System.out.println(stringLinkedList.toString());
    }
    
    public void dec(String key) {
        StringNode node = map.get(key);
        node = stringLinkedList.dec(key, node);
        if(node == null) map.remove(key);
        else map.put(key, node);
        //System.out.println(stringLinkedList.toString());
    }
    
    public String getMaxKey() {
        StringNode node = stringLinkedList.head.next;
        if(node == stringLinkedList.tail) return "";
        else return node.content.iterator().next();
    }
    
    public String getMinKey() {
        StringNode node = stringLinkedList.tail.prev;
        if(node == stringLinkedList.head) return "";
        else return node.content.iterator().next();
    }
}


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
// @lc code=end

