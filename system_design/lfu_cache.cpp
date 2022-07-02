/// Leet code #460. LFU Cache
/// Design and implement a data structure for Least Frequently 
/// Used (LFU) cache. It should support the following operations: get and put. 
///
/// get(key) - Get the value (will always be positive) of the key if the key 
///            exists in the cache, otherwise return -1.
/// put(key, value) - Set or insert the value if the key is not already present. 
///                   When the cache reaches its capacity, it should invalidate 
///                   the least frequently used item before inserting a new 
///                   item. For the purpose of this problem, when there is a 
///                   tie (i.e., two or more keys that have the same frequency), 
///                   the least recently used key would be evicted. 
///
/// Follow up:
/// Could you do both operations in O(1) time complexity?
/// Example: 
/// LFUCache cache = new LFUCache( 2 /* capacity */ );
/// cache.put(1, 1);
/// cache.put(2, 2);
/// cache.get(1);       // returns 1
/// cache.put(3, 3);    // evicts key 2
/// cache.get(2);       // returns -1 (not found)
/// cache.get(3);       // returns 3.
/// cache.put(4, 4);    // evicts key 1.
/// cache.get(1);       // returns -1 (not found)
/// cache.get(3);       // returns 3
/// cache.get(4);       // returns 4
/// </summary>
class LFUCache
{
private:
    size_t m_capacity;
    int m_minFreq;
    // map key to the frequency list position
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> m_keyMap;
    // map frequency to the value list
    unordered_map<int, list<pair<int, int>>> m_freqMap;
public:
    LFUCache(int capacity)
    {
        m_capacity = capacity;
        m_minFreq = 0;
    }

    int get(int key)
    {
        if (m_keyMap.count(key) == 0)
        {
            return -1;
        }
        pair<int, list<pair<int, int>>::iterator> freq_itr = m_keyMap[key];
        int frequency = freq_itr.first;
        list<pair<int, int>>::iterator key_val_itr = freq_itr.second;
        pair<int, int> key_val = *key_val_itr;
        // key_val_itr become invalid
        m_freqMap[frequency].erase(key_val_itr);
        if (m_freqMap[frequency].empty())
        {
            m_freqMap.erase(frequency);
            if (m_minFreq == frequency) m_minFreq++;
        }
        frequency++;
        m_freqMap[frequency].push_front(key_val);
        // new key value pair iterator
        key_val_itr = m_freqMap[frequency].begin();
        // assign back to kay map
        m_keyMap[key] = make_pair(frequency, key_val_itr);
        return key_val.second;
    }

    void put(int key, int value)
    {
        if (m_capacity == 0) return;
        list<pair<int, int>>::iterator key_val_itr;
        if (get(key) != -1)
        {
            key_val_itr = m_keyMap[key].second;
            key_val_itr->second = value;
        }
        else
        {
            if (m_keyMap.size() == m_capacity)
            {
                // erase LFU key from frequency map
                pair<int, int> key_val = m_freqMap[m_minFreq].back();
                m_freqMap[m_minFreq].pop_back();
				if (m_freqMap[m_minFreq].empty())
				{
					m_freqMap.erase(m_minFreq);
				}
                // erase LFU key from key map
                m_keyMap.erase(key_val.first);
            }
            m_minFreq = 1;
            m_freqMap[m_minFreq].push_front(make_pair(key,value));
            // new key value pair iterator
            key_val_itr = m_freqMap[m_minFreq].begin();
            // assign back to kay map
            m_keyMap[key] = make_pair(m_minFreq, key_val_itr);
        }
    }
};
