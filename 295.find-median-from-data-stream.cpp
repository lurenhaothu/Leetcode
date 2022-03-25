/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
    multiset<int> dict;
    decltype(dict.begin()) itr1, itr2;
public:
    MedianFinder() {
        // we should know that in multiset C++, the same element will always be added to the end.
    }
    
    void addNum(int num) {
        dict.insert(num);
        if(dict.size() == 1){
            itr1 = dict.begin();
            itr2 = dict.begin();
        }else if(dict.size() % 2 == 0){
            //now even
            if(num >= *itr2) itr2++;
            else itr1--;
        }else{
            //odd now
            if(num >= *itr2){
                itr1++;
            }else if(num < *itr1){
                itr2--;
            }else{
                itr1++;
                itr2--;
            }
        }
    }
    
    double findMedian() {
        double r = *itr1 + *itr2;
        return r / 2;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

