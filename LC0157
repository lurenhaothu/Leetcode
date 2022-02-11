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
    int read(char *buf, int n) {
        int rdn = n / 4;
        int rmd = n % 4;
        int r = 0;
        int m;
        char* pr = buf;
        for(int i = 0; i < rdn; i++){
            if((m = read4(pr)) == 4) pr += 4, r += 4;
            else{
                r += m;
                return r;
            }
        }
        m = read4(pr);
        if(m >= rmd) return n;
        else return r + m;
    }
};
