class Twitter {
private:
    unordered_map<int, unordered_set<int>> followings;
    vector<pair<int, int>> posts;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int j = posts.size() - 1;
        vector<int> feed;
        while(feed.size() < 10 && j >= 0)
        {
            if (posts[j].second == userId || followings[userId].contains(posts[j].second)) {
    feed.push_back(posts[j].first);
}
            j--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};
