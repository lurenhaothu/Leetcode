/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
/*

    I tried all optimization ways, change hashmap to vector then to array
    But it doesn't work, and I don't know why
    Exact same algorithm work for python 3 but not for C++
    This might be the magic of LeeCode. Damn

*/


class WordDictionary {
    //vector<WordDictionary*> dic = vector<WordDictionary*>(26, nullptr);
    WordDictionary* dic[26] = {nullptr};
    bool end = false;
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(char j : word){
            int i = j - 'a';
            //assert(i < 26 && i >= 0);
            if(!node->dic[i]){
                node->dic[i] = new WordDictionary();
            }
            node = node->dic[i];
        }
        node->end = true;
        return;
    }
    
    bool search(string word) {
        if(word.empty()) return end;
        WordDictionary* node = this;
        for(int j = 0; j < word.length(); j++){
            int i = word[j] - 'a';
            if(i == '.' - 'a'){
                for(auto k : node->dic){
                    if(!k) continue;
                    string tail = word.substr(j + 1, word.length() - j - 1);
                    if(k->search(tail)) return true;
                }
                return false;
            }
            //assert(i < 26 && i >= 0);
            if(!node->dic[i]) return false;
            else node = node->dic[i];
        }
        return node->end;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

