#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

struct Tweet {
    int user_id;
    int tweet_id;
    Tweet(int u_id, int t_id): user_id(u_id), tweet_id(t_id) {}
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // follow herself
        auto cur_follow = follow_table.find(userId);
        if (cur_follow == follow_table.end()) {
            auto tmp = follow_table.insert(pair<int, unordered_set<int>>(userId, unordered_set<int>()));
            tmp.first->second.insert(userId);
        }

        // other user
        for (auto each : recent_table) {
            // check follow
            auto followee_set = follow_table.find(each.first);
            if (followee_set != follow_table.end() && 
                followee_set->second.find(userId) != followee_set->second.end()) {
                // add recent
                each.second.push_back(Tweet(userId, tweetId));
            }
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        auto recent_list = recent_table.find(userId);
        if (recent_list == recent_table.end()) {
            return result;
        }
        for (auto each : recent_list->second) {
            result.push_back(each.tweet_id);
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        auto followee_set = follow_table.find(followerId);
        if (followee_set == follow_table.end()) {
            follow_table.insert(pair<int, unordered_set<int>>());
        }
        followee_set->second.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto follow_set = follow_table.find(followerId);
        if (follow_set == follow_table.end()) {
            return;
        }

        auto itr = follow_set->second.find(followeeId);
        if (itr == follow_set->second.end()) {
            return;
        }

        follow_set->second.erase(itr);

        // remove tweets from followeeId
        auto recent_list = recent_table.find(followerId);
        for (auto each = recent_list->second.begin(); each != recent_list->second.end(); ) {
            if (each->user_id == *itr) {
                each = recent_list->second.erase(each);
            } else {
                ++each;
            }
        }
    }

private:
    unordered_map<int, unordered_set<int>> follow_table;
    unordered_map<int, list<Tweet>> recent_table;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

 int main(int argc, char const *argv[]) {
     Twitter twitter;
     twitter.postTweet(1, 1);
     twitter.postTweet(2, 2);
     vector<int> recent = twitter.getNewsFeed(1);
     for (auto each : recent) {
        cout << each << " ";
     }
     cout << endl;
     return 0;
 }