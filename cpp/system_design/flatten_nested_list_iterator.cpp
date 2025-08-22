/// Leet code #341. Flatten Nested List Iterator       
/// Given a nested list of integers, implement an iterator to flatten it. 
/// Each element is either an integer, or a list -- whose elements may also 
/// be integers or other lists.
///
/// Example 1:
/// Given the list [[1,1],2,[1,1]],
/// By calling next repeatedly until hasNext returns false, the order of 
/// elements returned by next should be: [1,1,2,1,1]. 
///
/// Example 2:
/// Given the list [1,[4,[6]]],
/// By calling next repeatedly until hasNext returns false, the order of 
/// elements returned by next should be: [1,4,6]. 
///
/// This is the interface that allows for creating nested lists.
/// You should not implement it, or speculate about its implementation
/// Your NestedIterator object will be instantiated and called as such:
/// NestedIterator i(nestedList);
/// while (i.hasNext()) cout << i.next();

class NestedInteger 
{
private:
    vector<NestedInteger> m_NestedIntegers;
    int m_Integer;
    bool m_IsInteger;
    int m_Size;
public:
    // Constructure on single integter.
    NestedInteger()
    {
        m_Size = 0;
    }

    // Constructure on single integter.
    NestedInteger(int value)
    {
        m_Integer = value;
        m_IsInteger = true;
        m_Size = 1;
    }

    // Constructure on nested integers.
    NestedInteger(vector<NestedInteger> nested_integers)
    {
        m_NestedIntegers = nested_integers;
        m_IsInteger = false;
        m_Size = nested_integers.size();
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return m_IsInteger;
    };

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return m_Integer;
    };

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value)
    {
        m_Integer = value;
        m_IsInteger = true;
        m_NestedIntegers.clear();
        m_Size = 1;
    };

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni)
    {
        if (m_Size == 1 && isInteger())
        {
            m_NestedIntegers.push_back(m_Integer);
        }
        m_NestedIntegers.push_back((NestedInteger)ni);
        m_IsInteger = false;
        m_Size++;
    };

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const
    {
        return m_NestedIntegers;
    };
};


class NestedIterator {
private:
    deque<NestedInteger> m_NestedQueue;
    bool isEmpty(NestedInteger& ni)
    {
        if (ni.isInteger())
        {
            return false;
        }
        else
        {
            vector<NestedInteger> ni_list = ni.getList();
            for (size_t i = 0; i < ni_list.size(); i++)
            {
                if (!isEmpty(ni_list[i])) return false;
            }
            return true;
        }
    }
        
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (size_t i = 0; i < nestedList.size(); i++)
        {
            m_NestedQueue.push_back(nestedList[i]);
        }
    }

    int next() 
    {
        int value = 0;
        if (!m_NestedQueue.empty())
        {
            NestedInteger nested_integer = m_NestedQueue.front();
            m_NestedQueue.pop_front();
            if (nested_integer.isInteger())
            {
                value = nested_integer.getInteger();
            }
            else
            {
                vector<NestedInteger> nested_list = nested_integer.getList();
                while (!nested_list.empty())
                {
                    m_NestedQueue.push_front(nested_list.back());
                    nested_list.pop_back();
                }
                value = next();
            }
        }
        return value;
    }

    bool hasNext() 
    {
        bool has_next = false;

        while (!m_NestedQueue.empty())
        {
            NestedInteger ni = m_NestedQueue.front();
            if (isEmpty(ni))
            {
                m_NestedQueue.pop_front();
            }
            else
            {
                return true;
            }
        }
        return false;		
    }
};
