/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
    bool end;
    unordered_map<char, Trie*> tree;
public:
    Trie() {
        end = false;
    }
    
    void insert(string word) {
        if(word.length() == 0){
            end = true;
            return;
        }
        char c = word[0];
        if(tree.find(c) == tree.end()){
            tree[c] = new Trie();
        }
        word.erase(word.begin());
        tree[c]->insert(word);
        return;
    }
    
    bool search(string word) {
        if(word.length() == 0){
            return end;
        }
        char c = word[0];
        if(tree.find(c) == tree.end()) return false;
        else{
            word.erase(word.begin());
            return tree[c]->search(word);
        }
    }
    
    bool startsWith(string prefix) {
        if(prefix.length() == 0){
            return true;
        }
        char c = prefix[0];
        if(tree.find(c) == tree.end()) return false;
        else{
            prefix.erase(prefix.begin());
            return tree[c]->startsWith(prefix);
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

