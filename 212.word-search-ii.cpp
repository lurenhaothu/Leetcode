/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
#include<string>
#include<unordered_map>
using namespace std;

class Trie{
public:
    unordered_map<char, Trie*> dic;
    string w = "";
    void add(string s){
        Trie* node = this;
        for(auto i : s){
            if(node->dic.find(i) == node->dic.end()){
                node->dic[i] = new Trie();
            }
            node = node->dic[i];
        }
        node->w = s;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, 
                            vector<string>& words) {
        Trie T;
        for(auto w : words) T.add(w);
        vector<string> res;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                DFS(&T, board, i, j, res);
            }
        }
        return res;
    }
    void DFS(Trie* node, vector<vector<char>>& board, int i, int j, vector<string> &res){
        //i, j is the current node->letter
        char l = board[i][j];
        if(node->dic.find(l) == node->dic.end()) return;
        Trie* curnode = node->dic[l];
        if(!curnode->w.empty()){
            res.push_back(curnode->w);
            curnode->w = "";
        }
        board[i][j] = '*';
        vector<vector<int>> arr = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(auto s : arr){
            int ni = i + s[0];
            int nj = j + s[1];
            if(ni >= 0 && ni < board.size() &&
                nj >= 0 && nj < board[0].size()){
                char c = board[ni][nj];
                if(curnode->dic.find(c) == curnode->dic.end()) continue;
                DFS(curnode, board, ni, nj, res);
            }
        }
        board[i][j] = l;
        if(curnode->dic.empty()) node->dic.erase(l);
        return;
    }
};
// @lc code=end

