# https://leetcode.com/problems/design-hit-counter/description/

'''
Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).
Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.
Implement the HitCounter class:
HitCounter() Initializes the object of the hit counter system.
void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen at the same timestamp.
int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).

Example 1:
Input
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
Output
[null, null, null, null, 3, null, 4, 3]

Explanation
HitCounter hitCounter = new HitCounter();
hitCounter.hit(1);       // hit at timestamp 1.
hitCounter.hit(2);       // hit at timestamp 2.
hitCounter.hit(3);       // hit at timestamp 3.
hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
hitCounter.hit(300);     // hit at timestamp 300.
hitCounter.getHits(300); // get hits at timestamp 300, return 4.
hitCounter.getHits(301); // get hits at timestamp 301, return 3.

Constraints:
1 <= timestamp <= 2 * 109
All the calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing).
At most 300 calls will be made to hit and getHits.
 
Follow up: What if the number of hits per second could be huge? Does your design scale?
'''



class HitCounter:

    def __init__(self):
        self.timestamp_hits=deque()

    def hit(self, timestamp: int) -> None:
        self.timestamp_hits.append(timestamp)


    def getHits(self, timestamp: int) -> int:
        while self.timestamp_hits and self.timestamp_hits[0]<=timestamp-300:
            self.timestamp_hits.popleft()
        return len(self.timestamp_hits)

# with bounded memory, amortized O(1) operations, and precise window semantics:


# Space Efficiency:
# Deque size ≤ hits in last 300 seconds → O(1) bounded space (e.g., max 300 hits if 1/sec)
# Time Efficiency:
# Each hit is added once and removed once → amortized O(1) per operation
# Correctness:
# Window = (timestamp - 300, timestamp] → hits at timestamp-300 are expired (excluded), so condition <= timestamp-300 is precise
# Handles Duplicates:
# Multiple hits at same timestamp? All expired together when window passes

# Scenario	Steps	Result	Why Correct
# Duplicate timestamps
# hit(1)×3	getHits(300) → keeps all (1 > 0)
# getHits(301) → removes all (1 ≤ 1)	3 → 0	Window = (timestamp-300, timestamp]
# At 301: (1, 301] excludes timestamp=1
# Boundary precision
# hit(1), hit(300), hit(301)	getHits(301):
# - Remove 1 (1 ≤ 1)
# - Keep 300, 301	2	Window (1, 301] includes 300/301 ✅
# Excludes 1 ✅
# Burst traffic
# 10,000 hits @ t=1	getHits(301):
# - Pops all 10k hits in one pass
# - Deque becomes empty	0	Memory freed immediately ✅
# No leak even after massive burst
# Stale hits + new hits
# hit(1), hit(2), hit(400)	getHits(400):
# - Remove 1,2 (≤100)
# - Keep 400	1	Only hits in (100, 400] counted ✅
# Back-to-back queries
# hit(1), getHits(100), getHits(400)	First call: keeps 1 (1 > -200)
# Second call: removes 1 (1 ≤ 100)	1 → 0	State persists correctly between calls ✅
# No hits	getHits(100)	0	Empty deque handled safely ✅
# 💡 Why This Scales
# Metric	Behavior	Real-World Impact
# Memory	Bounded by hits in last 300s	Handles 1M hits/sec → deque holds ≤ 300M entries (manageable)
# Time per getHits	Amortized O(1)	Each hit pushed/popped once → total work = O(total hits)
# Timestamp order	Relies on strictly increasing timestamps (per problem)	No sorting needed → optimal for streaming data
# Window semantics	(timestamp-300, timestamp]	Matches problem spec: hits at timestamp-300 are excluded
# 🌐 Real-World Context
# This is the exact pattern used in:

# Rate limiters (API gateways)
# Sliding window analytics (Redis ZREMRANGEBYSCORE)
# Network traffic monitors