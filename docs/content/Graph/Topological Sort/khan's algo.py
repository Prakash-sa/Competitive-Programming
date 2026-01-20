from collections import deque

def topological_sort(adj_list, n):

  # calculate indegree of each node
  indegree = [0] * n
  for u in adj_list:
      for v in adj_list[u]:
          indegree[v] += 1

  # enqueue nodes with indegree 0
  queue = deque([u for u in range(n) if indegree[u] == 0])

  order = []
  while queue:
      u = queue.popleft()
      order.append(u)
      
      for v in adj_list.get(u, []):
          indegree[v] -= 1
          if indegree[v] == 0:
              queue.append(v)

  return order if len(order) == n else []

# Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph. This is the same complexity as BFS - we visit each vertex and edge once.

# Space Complexity: O(V) where V is the number of vertices in the graph. This is due to the data structure we use to store the indegrees of each vertex, and the queue we use to store vertices with an indegree of 0, both of which store up to V elements.