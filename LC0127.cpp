class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int l = beginWord.length();
        unordered_map<string, int> dic;
        for(int i = 0; i < wordList.size(); i++){
            if(dic.find(wordList[i]) == dic.end()) dic[wordList[i]] = i;
        }
        if(dic.find(endWord) == dic.end()) return 0;
        vector<int> step(wordList.size(), 0);
        queue<string> qF, qB;
        qF.push(beginWord);
        step[dic[beginWord]] = 1;
        //dic.erase(beginWord);
        qB.push(endWord);
        step[dic[endWord]] = -1;
        //dic.erase(endWord);
        bool stop = false;
        while(!qF.empty() && !qB.empty() && !stop){
            if(qF.size() <= qB.size()){
                int qsize = qF.size();
                for(int j = 0; j < qsize; j++){
                    string word = qF.front();
                    qF.pop();
                    int stepWord = step[dic[word]];
                    for(int i = 0; i < l; i++){
                        char s = word[i];
                        for(char k = 'a'; k <= 'z'; k++){
                            if(k == s) continue;
                            word[i] = k;
                            if(dic.find(word) != dic.end()){
                                //cout<<word;
                                if(step[dic[word]] == 0){
                                    step[dic[word]] = stepWord + 1;
                                    qF.push(word);
                                }else if(step[dic[word]] < 0){
                                    cout<<word;
                                    stop = true;
                                    return -step[dic[word]] + stepWord;
                                }
                                //dic.erase(word);
                            }
                        }
                        word[i] = s;
                    }
                }
            }else{
                int qsize = qB.size();
                for(int j = 0; j < qsize; j++){
                    string word = qB.front();
                    qB.pop();
                    int stepWord = step[dic[word]];
                    for(int i = 0; i < l; i++){
                        char s = word[i];
                        for(char k = 'a'; k <= 'z'; k++){
                            if(k == s) continue;
                            word[i] = k;
                            if(dic.find(word) != dic.end()){
                                if(step[dic[word]] == 0){
                                    step[dic[word]] = stepWord - 1;
                                    qB.push(word);
                                }else if(step[dic[word]] > 0){
                                    cout<<word;
                                    stop = true;
                                    return step[dic[word]] - stepWord;
                                }
                                //dic.erase(word);
                            }
                        }
                        word[i] = s;
                    }
                }
            }
        }
        return 0;
    }
};
