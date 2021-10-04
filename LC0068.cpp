class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        vector<int> length;
        for(int i = 0; i < n; i++){
            length.push_back(words[i].length());
        }
        int pr = 0, end = 0, rowWidth;
        while(pr != n){
            rowWidth = length[pr];
            while(end < n - 1){//pr->end is the section we need for the next row
                end++;
                rowWidth += length[end];
                if(rowWidth + end - pr > maxWidth){
                    rowWidth -= length[end];
                    end--;
                    break;
                }
            }
            //cout<<pr<<end<<endl;
            if(end == n - 1){//if this is the last row
                int space = maxWidth - rowWidth - (end - pr);
                string r = words[pr];
                for(int i = pr + 1; i <= end; i++){
                    r += ' ';
                    r += words[i];
                }
                r += string(space, ' ');
                res.push_back(r);
            }else{//not the last row
                int space = maxWidth - rowWidth;
                string r = words[pr];
                if(end == pr){
                    r += string(space, ' ');
                }else{
                    int base = space / (end - pr);
                    int carry = space % (end - pr);
                    for(int i = pr + 1; i <= end; i++){
                        if(i - pr <= carry){
                            r += string(base + 1, ' ');
                            r += words[i];
                        }else{
                            r += string(base, ' ');
                            r += words[i];
                        }
                    }
                }
                res.push_back(r);
            }
            pr = end + 1;
            end = pr;
        }
        return res;
    }
};
