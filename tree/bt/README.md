

- To be a tree, a graph must satisfy two requirements:

1. It is acyclic. It contains no cycles (or "loops").
2. It is connected. For any given node in the graph, every node is reachable. All nodes are reachable through
one path in the graph.


# Types of Binary Tree

- Full Binary Tree:- A Binary Tree is a full binary tree if every node has 0 or 2 children. The following are the examples of a full binary tree. We can also say a full binary tree is a binary tree in which all nodes except leaf nodes have two children. 

```
               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40

```

- Complete Binary Tree:-  A Binary Tree is a Complete Binary Tree if all the levels are completely filled except possibly the last level and the last level has all keys as left as possible.

```
               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9 

```


- Perfect Binary Tree:- A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same level. 

```
               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40

```

- Balanced Binary Tree:- A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes. For Example, the AVL tree maintains O(Log n) height by making sure that the difference between the heights of the left and right subtrees is at most 1. Red-Black trees maintain O(Log n) height by making sure that the number of Black nodes on every root to leaf paths is the same and there are no adjacent red nodes. Balanced Binary Search trees are performance-wise good as they provide O(log n) time for search, insert and delete. 



# Views

## Bottom View

- Use map and queue for bfs
- 

## Boundary

- Left Boundary of root->left
- Leaf Boundary of root->left and root->right
- Right Boundary of root->right

## Zigzag level

- Reverse at alternative level


# Cousins


## Sum



## is Cousins

- same level and not siblings


# Subtree

- 


# is graph is tree

- is cyclic ?



# isomorphic

- Two trees are called isomorphic if one can be obtained from another by a series of flips.i.e. by swapping left and right children of several nodes. Any number of nodes at any level can have their children swapped.



# path sum

- 



# largest independent set

- inclusion and exclusion

