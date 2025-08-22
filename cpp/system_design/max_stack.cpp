/// Leet code #716. Max Stack
///
/// Design a max stack that supports push, pop, top, peekMax and popMax.
///
/// push(x) -- Push element x onto stack.
/// pop() -- Remove the element on top of the stack and return it.
/// top() -- Get the element on the top.
/// peekMax() -- Retrieve the maximum element in the stack.
/// popMax() -- Retrieve the maximum element in the stack, and remove it. 
/// If you find more than one maximum elements, only remove the top-most 
/// one.
/// Example 1:
/// MaxStack stack = new MaxStack();
/// stack.push(5); 
/// stack.push(1);
/// stack.push(5);
/// stack.top(); -> 5
/// stack.popMax(); -> 5
/// stack.top(); -> 1
/// stack.peekMax(); -> 5
/// stack.pop(); -> 1
/// stack.top(); -> 5
/// Note:
/// -1e7 <= x <= 1e7
/// Number of operations won't exceed 10000.
/// The last four operations won't be called when stack is empty.

class MaxStack {
private:
	map<int, stack<int>> m_ValueMap;
	map<int, int> m_StackMap;
	int m_Index;
public:
	/// <summary>
	/// Constructor an empty max stack
	/// </summary>
	MaxStack() 
	{
		m_Index = 0;
	}

	void push(int x) 
	{
		// Add to value map, biggest first
		m_ValueMap[-x].push(m_Index);
		// Add to stack map, last one first
		m_StackMap[-m_Index] = x;
		m_Index++;
	}

	int pop() 
	{
		// take first item from m_StackMap, which is the last item based on index
		auto itr = m_StackMap.begin();
		int index = -itr->first;
		int value = itr->second;
		m_StackMap.erase(-index);
		// take out the top index from specific value 
		m_ValueMap[-value].pop();
		if (m_ValueMap[-value].empty()) m_ValueMap.erase(-value);
		return value;
	}

	int top() 
	{
		// take first item from m_StackMap, which is the last item based on index
		auto itr = m_StackMap.begin();
		int index = -itr->first;
		int value = itr->second;
		return value;
	}

	int peekMax() 
	{
		// take first item from m_ValueMap, and the first one in the queue
		auto itr = m_ValueMap.begin();
		int value = -itr->first;
		int index = itr->second.top();
		return value;
	}

	int popMax() 
	{
		// take first item from m_ValueMap, and the first one in the queue
		auto itr = m_ValueMap.begin();
		int value = -itr->first;
		int index = itr->second.top();
		itr->second.pop();
		if (itr->second.empty()) m_ValueMap.erase(itr->first);
		m_StackMap.erase(-index);
		return value;
	}
};
