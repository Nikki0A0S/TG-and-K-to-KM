//https://leetcode.com/problems/design-twitter/

struct User{
    unordered_set<User*> conn;
    ListNode* tweets;
    User(){
        tweets = NULL;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, User*> users;
    Twitter() {
        
    }
    
    void checkUser(int id){
        if(users.find(id) == users.end()){
            users[id] = new User();
        }
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        checkUser(userId);
        ListNode* next = new ListNode(tweetId);
        next->next = users[userId]->tweets;
        users[userId]->tweets = next;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        checkUser(userId);
        priority_queue<ListNode*> pq;
        if(users[userId]->tweets){
            pq.push(users[userId]->tweets);
        }
        for(User* u : users[userId]->conn){
            if(u->tweets){
                pq.push(u->tweets);
            }
        }
        int i = 0;
        while(!pq.empty() && i < 10){
            ListNode* t = pq.top(); pq.pop();
            res.push_back(t->val);
            t = t->next;
            if(t){
                pq.push(t);
            }
            i++;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        checkUser(followerId);
        checkUser(followeeId);
        users[followerId]->conn.insert(users[followeeId]);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        checkUser(followerId);
        checkUser(followeeId);
        users[followerId]->conn.erase(users[followeeId]);
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