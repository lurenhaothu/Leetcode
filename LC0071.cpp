class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        vector<string> stack;
        int start = 0, end;
        while(start < n){
            for(; start < n; start++){
                if(path[start] != '/') break;
            }
            if(start == n) break;
            for(end = start; end < n; end++){
                if(path[end] == '/') break;
            }
            string file = path.substr(start, end - start);
            if(file == ".") {start = end;continue;}
            else if(file == ".." && stack.size() != 0) stack.pop_back();
            else if(file == ".." && stack.size() == 0) {start = end;continue;}
            else stack.push_back(path.substr(start, end - start));
            start = end;
        }
        string res;
        for(int i = 0; i < stack.size(); i++){
            res += '/';
            res += stack[i];
        }
        if(res.length() == 0) res += '/';
        return res;
    }
};
