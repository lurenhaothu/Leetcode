/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char classbuf[4];
    int bufpos = 4;
    int bufend = 4;
    char* prebuf = NULL;

    int read(char *buf, int n) {
        if(buf != prebuf){
            prebuf = buf;
            classbuf[0] = '\0';
            classbuf[1] = '\0';
            classbuf[2] = '\0';
            classbuf[3] = '\0';
            bufpos = 4;
            bufend = 4;
        }//initialization
        char *wpr = buf;
        for(int i = 0; i < n; i++){
            if(bufpos == 4){
                bufend = read4(classbuf);
                bufpos = 0;
            }
            if(bufpos == bufend) break;
            *wpr = classbuf[bufpos];
            wpr++;
            bufpos++;
        }
        return wpr - buf;
    }
};
