class DoubleListNode{
    public:
    int val;
    int key;
    DoubleListNode *next;
    DoubleListNode *previous;
    DoubleListNode(int k, int v){val = v;key = k;}
};

class LRUCache {
public:
    DoubleListNode* s;
    DoubleListNode* t;
    unordered_map<int, DoubleListNode*> dic;
    int cap;
    int count;
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
        s = new DoubleListNode(-1, -1);
        t = new DoubleListNode(-1, -1);
        s->next = t;
        t->previous = s;
    }
    
    int get(int key) {
        if(dic.find(key) == dic.end()){
            return -1;
        }else{
            update(key);
            return dic[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(dic.find(key) == dic.end()){
            if(count == cap){
                int k = t->previous->key;
                t->previous = dic[k]->previous;
                dic[k]->previous->next = t;
                dic.erase(k);
                count--;
            }
            dic[key] = new DoubleListNode(key, value);
            dic[key]->next = s->next;
            dic[key]->previous = s;
            s->next = dic[key];
            dic[key]->next->previous = dic[key];
            count++;
        }else{
            dic[key]->val = value;
            update(key);
        }
        return;

    }
    void update(int key){
        dic[key]->next->previous = dic[key]->previous;
        dic[key]->previous->next = dic[key]->next;
        dic[key]->next = s->next;
        dic[key]->previous = s;
        s->next = dic[key];
        dic[key]->next->previous = dic[key];
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
