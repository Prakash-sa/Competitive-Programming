/// LeetCode #355. Design Twitter
/// Design a simplified version of Twitter where users can post tweets, 
/// follow/unfollow another user and 
/// is able to see the 10 most recent tweets in the user's news feed. 
/// Your design should support the following methods:
/// 1.postTweet(userId, tweetId): Compose a new tweet.
/// 2.getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's 
///   news feed. 
/// Each item in the news feed must be posted by users who the user followed 
/// or by the user herself. 
/// Tweets must be ordered from most recent to least recent.
/// 3.follow(followerId, followeeId): Follower follows a followee.
/// 4.unfollow(followerId, followeeId): Follower unfollows a followee.
/// Example: 
/// Twitter twitter = new Twitter();
/// User 1 posts a new tweet (id = 5).
/// twitter.postTweet(1, 5);
/// User 1's news feed should return a list with 1 tweet id -> [5].
/// twitter.getNewsFeed(1);
/// User 1 follows user 2.
/// twitter.follow(1, 2);
/// User 2 posts a new tweet (id = 6).
/// twitter.postTweet(2, 6);
/// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
/// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
/// twitter.getNewsFeed(1);
///
/// User 1 unfollows user 2.
/// twitter.unfollow(1, 2);
/// User 1's news feed should return a list with 1 tweet id -> [5],
/// since user 1 is no longer following user 2.
/// twitter.getNewsFeed(1);

class Twitter
{
private:
    long m_TimeTicks;

	unordered_map<int, vector<pair<long, int>>> m_TwitterList;
    unordered_map<int, unordered_set<int>> m_FollowList;

public:
    /// <summary>
    /// Constructor an empty Twitter cache
    /// </summary>
    /// <returns></returns>
    Twitter()
    {
        m_TimeTicks = 0;
    }

    /// <summary>
    /// Destructor of an Twitter
    /// </summary>
    /// <returns></returns>
    ~Twitter()
    {
    }

    /// <summary>
    /// Compose a new tweet
    /// </summary>
    /// <returns></returns>
    void postTweet(int userId, int tweetId)
    {
        m_TimeTicks++;
        long now = m_TimeTicks;

        m_TwitterList[userId].push_back(make_pair(m_TimeTicks, tweetId));
    }

    /// <summary>
    /// Retrieve the 10 most recent tweet ids in the user's news feed. 
    /// Each item in the news feed must be posted by users who the user 
	/// followed or by the user herself. 
    /// Tweets must be ordered from most recent to least recent.
    /// </summary>
    /// <returns></returns>
    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;
        priority_queue <pair<long, pair<int,int>>> candidate_list;
		if (!m_TwitterList[userId].empty())
		{
			int clock = m_TwitterList[userId].back().first;
			int index = (int)m_TwitterList[userId].size() - 1;
			candidate_list.push(make_pair(clock, make_pair(userId, index)));
		}
		for (int followee : m_FollowList[userId])
		{
			if (!m_TwitterList[followee].empty())
			{
				int clock = m_TwitterList[followee].back().first;
				int index = (int)m_TwitterList[followee].size() - 1;
				candidate_list.push(make_pair(clock, make_pair(followee, index)));
			}
		}

		for (size_t i = 0; i < 10; i++)
		{
			if (candidate_list.empty())
			{
				break;
			}
			pair<long, pair<int, int>> tweet_itr = candidate_list.top();
			candidate_list.pop();
			int user_id = tweet_itr.second.first;
			int index = tweet_itr.second.second;
			int tweet_id = m_TwitterList[user_id][index].second;
			result.push_back(tweet_id);
			// push the next tweet of this user to priority queue
			if (index > 0)
			{
				index--;
				int clock = m_TwitterList[user_id][index].first;
				candidate_list.push(make_pair(clock, make_pair(user_id, index)));
			}
		}

        return result;
    }

    /// <summary>
    /// Follower follows a followee. If the operation is invalid, it should 
	/// be a no-op.
    /// </summary>
    /// <param name="followerId">The follower id</param>
    /// <param name="followeeId">The followee id</param>
    /// <returns></returns>
    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            m_FollowList[followerId].insert(followeeId);
        }
    }

    /// <summary>
    /// Follower unfollows a followee. If the operation is invalid, it should 
	/// be a no-op.
    /// </summary>
    /// <param name="followerId">The follower id</param>
    /// <param name="followeeId">The followee id</param>
    /// <returns></returns>
    void unfollow(int followerId, int followeeId)
    {
        m_FollowList[followerId].erase(followeeId);
    }
};
