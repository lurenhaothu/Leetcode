class Solution {
public:
    int totalStep;
    int controlStep, controlStepB;
    unordered_set<string> controlWord;
    int l;
    vector<vector<string>> res;
    unordered_map<string, vector<vector<string>>> resF, resB;
    unordered_map<string, int> dic;
    unordered_map<string, vector<string>> BigDic;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        l = endWord.size();
        wordList.push_back(beginWord);
        for(int i = 0; i < wordList.size(); i++){
            if(dic.find(wordList[i]) == dic.end()){
                dic[wordList[i]] = 0;
            }
        }
        if(dic.find(endWord) == dic.end()) return {};
        queue<string> qF, qB;
        qF.push(beginWord);
        dic[beginWord] = 1;
        qB.push(endWord);
        dic[endWord] = -1;
        bool stop = false;
        
        //new last time update!
        
        while(!qF.empty() && !qB.empty() && !stop){
            if(qF.size() <= qB.size()){
                int qsize = qF.size();
                for(int i = 0; i < qsize; i++){
                    string word = qF.front();
                    string w = word;
                    qF.pop();
                    int stepWord = dic[word];
                    for(int j = 0; j < l; j++){
                        char s = word[j];
                        for(char k = 'a'; k <= 'z'; k++){
                            if(k == s) continue;
                            word[j] = k;
                            if(dic.find(word) != dic.end()){
                                if(dic[word] == 0){
                                    BigDic[w].push_back(word);
                                    dic[word] = stepWord + 1;
                                    qF.push(word);
                                }else if(dic[word] < 0){
                                    BigDic[w].push_back(word);
                                    //cout<<word;
                                    stop = true;
                                    controlStep = stepWord + 1;
                                    controlStepB = dic[word];
                                    totalStep = -dic[word] + stepWord;
                                    controlWord.insert(word);
                                }else if(dic[word] == stepWord + 1){
                                    BigDic[w].push_back(word);
                                }
                            }
                        }
                        word[j] = s;
                    }
                }
            }else{
                int qsize = qB.size();
                for(int i = 0; i < qsize; i++){
                    string word = qB.front();
                    string w = word;
                    qB.pop();
                    int stepWord = dic[word];
                    for(int j = 0; j < l; j++){
                        char s = word[j];
                        for(char k = 'a'; k <= 'z'; k++){
                            if(k == s) continue;
                            word[j] = k;
                            if(dic.find(word) != dic.end()){
                                if(dic[word] == 0){
                                    BigDic[w].push_back(word);
                                    dic[word] = stepWord - 1;
                                    qB.push(word);
                                }else if(dic[word] > 0){
                                    BigDic[w].push_back(word);
                                    //cout<<word;
                                    stop = true;
                                    totalStep = dic[word] - stepWord;
                                    controlStep = dic[word];
                                    controlStepB = stepWord - 1;
                                    controlWord.insert(word);
                                }else if(dic[word] == stepWord - 1){
                                    BigDic[w].push_back(word);
                                }
                            }
                        }
                        word[j] = s;
                    }
                }
            }
        }
        //cout<<totalStep<<controlStepB;
        vector<string> ansF, ansB;
        ansF.push_back(beginWord);
        ansB.push_back(endWord);
        DFSF(ansF, 1);
        DFSB(ansB, -1);
        for(string word : controlWord){
            //cout<<word;
            for(vector<string> rF : resF[word]){
                //for(string a : rF) cout<<a<<' ';
                for(vector<string> rB : resB[word]){
                    //for(string a : rB) cout<<a<<' ';
                    reverse(rB.begin(), rB.end());
                    rB.insert(rB.begin(), rF.begin(), rF.end() - 1);
                    res.push_back(rB);
                }
            }
        }
        return res;
    }
    void DFSF(vector<string> &ansF, int step){
        if(step == controlStep){
            if(controlWord.find(ansF.back()) != controlWord.end()) resF[ansF.back()].push_back(ansF);
            return;
        }
        string word = ansF.back();
        for(int j = 0; j < BigDic[word].size(); j++){
            ansF.push_back(BigDic[word][j]);
            DFSF(ansF, step + 1);
            ansF.pop_back();
        }
        return;
    }
    void DFSB(vector<string> &ansB, int step){
        if(step == controlStepB){
            if(controlWord.find(ansB.back()) != controlWord.end())resB[ansB.back()].push_back(ansB);
            return;
        }
        string word = ansB.back();
        for(int j = 0; j < BigDic[word].size(); j++){
            ansB.push_back(BigDic[word][j]);
            DFSB(ansB, step - 1);
            ansB.pop_back();
        }
        return;
    }
};
