/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter {
    vector<unordered_set<int>> followList = vector<unordered_set<int>>(501, unordered_set<int>{});
    vector<vector<pair<int, int>>> tweets = vector<vector<pair<int, int>>>(501, vector<pair<int, int>>{});
    int curTime = 0;
public:
    Twitter() {
        for(int i = 0; i <= 500; i++){
            followList[i].insert(i);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(curTime, tweetId));
        curTime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        map<int, tuple<int, int, int>> tweetSet; //postTime, userid, index, tweetid;
        for(auto& i : followList[userId]){
            if(tweets[i].empty()) continue;
            else{
                tweetSet[tweets[i].back().first] = make_tuple(i, tweets[i].size() - 1, tweets[i].back().second);
            }
        }
        vector<int> res;
        while(res.size() < 10 && !tweetSet.empty()){
            auto itr = tweetSet.rbegin();
            res.push_back(get<2>(itr->second));
            if(get<1>(itr->second) != 0){
                int nextIndex = get<1>(itr->second) - 1;
                int userId = get<0>(itr->second);
                tweetSet[tweets[userId][nextIndex].first] = make_tuple(userId, nextIndex, tweets[userId][nextIndex].second);
            }
            tweetSet.erase(itr->first);
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

