#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>

// a mess code
// to long to maintain
// brute force method
// each user maintain its recent_list, follow_set, history_list

using namespace std;

struct Tweet {
    int user_id;
    int tweet_id;
    int sequence;

    Tweet(): user_id(0), tweet_id(0), sequence(0) {}
    Tweet(int u_id, int t_id, int s): user_id(u_id), tweet_id(t_id), sequence(s) {}
    Tweet(const Tweet& c): user_id(c.user_id), tweet_id(c.tweet_id), sequence(c.sequence) {}
};

class User {
    static int glo_seq_num;

public:
    User(int u_id): user_id(u_id) {
        follow_set.insert(u_id);
    }

    Tweet postTweet(int tweetId) {
        Tweet tweet(user_id, tweetId, glo_seq_num++);
        history_tweets.push_back(tweet);
        addRecentTweet(tweet);
        return tweet;
    }

    void follow(int followerId, vector<Tweet> follower_tweets) {
        if (follow_set.count(followerId) > 0) {
            return;
        }
        follow_set.insert(followerId);
        for (int i = 0; i < follower_tweets.size(); ++i) {
            addRecentTweet(follower_tweets[i]);
        }
    }

    void unfollow(int followerId) {
        if (follow_set.count(followerId) == 0) {
            return;
        }
        if (user_id == followerId) { // Trap: can un subscribe self ? discuss with interviewer
            return;
        }

        for (auto itr = recent_tweets.begin(); itr != recent_tweets.end(); ) {
            if (itr->user_id == followerId) {
                itr = recent_tweets.erase(itr);
            } else {
                ++itr;
            }
        }
              
        follow_set.erase(followerId);
    }

    void addRecentTweet(Tweet tweet) {
        if (follow_set.count(tweet.user_id) == 0) {
            return;
        }
        auto itr = recent_tweets.begin();
        bool tail = true;
        for (; tail && itr != recent_tweets.end(); ++itr) {
            if (itr->sequence < tweet.sequence) {
                recent_tweets.insert(itr, tweet);
                tail = false;
            }
        }
        if (tail) {
            recent_tweets.push_back(tweet);
        }
    }

    vector<Tweet> getLastHistoryTweet() {
        if (history_tweets.size() < 10) {
            return history_tweets;
        }
        return vector<Tweet>(history_tweets.rbegin(), history_tweets.rbegin() + 10);
    }

    vector<int> getRecentTweet() {
        vector<int> result;
        int num = recent_tweets.size() < 10 ? recent_tweets.size() : 10;
        auto itr = recent_tweets.begin();
        for (int i = 0; i < num; ++i) {
            result.push_back(itr->tweet_id);
            ++itr;
        }
        return result;
    }

private:
    int user_id;
    list<Tweet> recent_tweets;
    vector<Tweet> history_tweets;
    unordered_set<int> follow_set;
};

int User::glo_seq_num = 0;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        User& u = getUser(userId);
        Tweet tweet = u.postTweet(tweetId);

        for (auto itr = user_table.begin(); itr != user_table.end(); ++itr) {
            if (itr->first != userId) {
                itr->second.addRecentTweet(tweet);
            }
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        User& u = getUser(userId);
        return u.getRecentTweet();
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        User& u = getUser(followeeId);
        User& f = getUser(followerId);
        f.follow(followeeId, u.getLastHistoryTweet());
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        User& u = getUser(followerId);
        u.unfollow(followeeId);
    }

    User& getUser(int userId) {
        auto itr = user_table.find(userId);
        if (itr == user_table.end()) {
            return user_table.insert(pair<int, User>(userId, User(userId))).first->second;
        }
        return itr->second;
    }

private:
    unordered_map<int, User> user_table;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

 void debugPrint(vector<int> num) {
    for (auto each : num) {
        cout << each << " ";
    }
    cout << endl;
 }

 int main(int argc, char const *argv[]) {
    Twitter twitter;

    twitter.postTweet(1, 1);
    twitter.postTweet(1, 2);
    twitter.postTweet(1, 3);
    twitter.postTweet(1, 4);
    twitter.postTweet(1, 5);
    twitter.postTweet(1, 6);
    twitter.postTweet(1, 7);
    twitter.postTweet(1, 8);
    twitter.postTweet(1, 9);
    twitter.postTweet(1, 10);
    twitter.postTweet(1, 11);
    twitter.postTweet(1, 12);

    debugPrint(twitter.getNewsFeed(2));
     
    return 0;
 }