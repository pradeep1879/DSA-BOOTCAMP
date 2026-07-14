# Linked List

A **Linked List** is a linear data structure where elements are stored in nodes. Each node contains:

- **Data** – The value stored in the node.
- **Pointer (Reference)** – The address of the next node.

Unlike arrays, linked lists do not store elements in contiguous memory locations.

---

# Table of Contents

- Introduction
- Types of Linked Lists
- Advantages
- Disadvantages
- Time Complexity
- Operations
- Implementation
- Applications
- Interview Questions

---

# Introduction

A linked list consists of a sequence of nodes connected through pointers.

```
+------+------+
| Data | Next | ------>
+------+------+
```

Example:

```
10 -> 20 -> 30 -> 40 -> NULL
```

Each node stores the data and the address of the next node.

---

# Types of Linked Lists

## 1. Singly Linked List

Each node points to the next node only.

```
10 -> 20 -> 30 -> NULL
```

---

## 2. Doubly Linked List

Each node has two pointers.

- Previous
- Next

```
NULL <- 10 <-> 20 <-> 30 -> NULL
```

---

## 3. Circular Linked List

The last node points back to the first node.

```
10 -> 20 -> 30
^            |
|____________|
```

---

## 4. Circular Doubly Linked List

Each node has previous and next pointers, and both ends are connected.

---

# Node Structure

### C++

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};
```

---

# Basic Operations

## Traversal

Visit every node.

```
Head
 |
 v
10 -> 20 -> 30 -> NULL
```

Time Complexity:

```
O(n)
```

---

## Insertion

### At Beginning

Before

```
10 -> 20 -> 30
```

After inserting 5

```
5 -> 10 -> 20 -> 30
```

Time Complexity

```
O(1)
```

---

### At End

Before

```
10 -> 20 -> 30
```

After

```
10 -> 20 -> 30 -> 40
```

Time Complexity

```
O(n)
```

With Tail Pointer

```
O(1)
```

---

### At Specific Position

Example

Insert 25 after 20

```
10 -> 20 -> 25 -> 30
```

Time Complexity

```
O(n)
```

---

# Deletion

## Delete First Node

```
10 -> 20 -> 30

↓

20 -> 30
```

Time

```
O(1)
```

---

## Delete Last Node

```
10 -> 20 -> 30

↓

10 -> 20
```

Time

```
O(n)
```

---

## Delete by Value

Delete 20

```
10 -> 20 -> 30

↓

10 -> 30
```

Time

```
O(n)
```

---

# Searching

Search for an element by traversing the list.

```
10 -> 20 -> 30 -> 40
```

Search 30

Result:

```
Found
```

Time Complexity

```
O(n)
```

---

# Reverse Linked List

Before

```
1 -> 2 -> 3 -> 4 -> NULL
```

After

```
4 -> 3 -> 2 -> 1 -> NULL
```

Time Complexity

```
O(n)
```

Space Complexity

```
O(1)
```

---

# Time Complexity

| Operation | Complexity |
|-----------|------------|
| Access | O(n) |
| Search | O(n) |
| Insert at Beginning | O(1) |
| Insert at End | O(n) |
| Delete Beginning | O(1) |
| Delete End | O(n) |
| Reverse | O(n) |

---

# Advantages

- Dynamic size
- Efficient insertion and deletion
- No memory wastage
- Does not require contiguous memory
- Easy implementation of stacks and queues

---

# Disadvantages

- Sequential access only
- Extra memory for pointers
- Poor cache locality
- Cannot access elements directly using index

---

# Applications

- Music Playlist
- Browser History
- Undo/Redo Feature
- Image Viewer
- Hash Tables (Separate Chaining)
- Graph Adjacency List
- Polynomial Representation
- Memory Management
- File Systems

---

# Comparison with Array

| Feature | Array | Linked List |
|----------|--------|------------|
| Memory | Contiguous | Non-contiguous |
| Size | Fixed | Dynamic |
| Random Access | O(1) | O(n) |
| Insert/Delete | O(n) | O(1) at head |
| Extra Memory | No | Pointer Required |

---

# Common Interview Problems

- Reverse Linked List
- Detect Cycle (Floyd's Algorithm)
- Find Middle Node
- Merge Two Sorted Lists
- Remove Nth Node from End
- Palindrome Linked List
- Intersection of Two Lists
- Rotate Linked List
- Reverse in K Groups
- Copy List with Random Pointer
- Flatten Linked List
- Sort Linked List
- Add Two Numbers
- Remove Duplicates
- Odd-Even Linked List

---

# Important Algorithms

## Floyd Cycle Detection

Also called:

- Tortoise and Hare Algorithm

Time:

```
O(n)
```

Space:

```
O(1)
```

---

## Find Middle Node

Use Slow and Fast Pointer.

```
Slow -> moves 1 step
Fast -> moves 2 steps
```

---

## Reverse Linked List

Use three pointers:

```
prev
current
next
```

---

# Memory Representation

```
Head
 |
 v

+------+-------+
| 10   |   *--------+
+------+-------+    |
                    |
                    v
              +------+-------+
              | 20   |   *--------+
              +------+-------+    |
                                  |
                                  v
                            +------+------+
                            | 30   | NULL |
                            +------+------+
```

---

# Practice Questions

### Easy

- Print Linked List
- Count Nodes
- Search Element
- Insert at Beginning
- Insert at End
- Delete First Node

### Medium

- Reverse Linked List
- Find Middle
- Detect Loop
- Remove Duplicates
- Merge Sorted Lists
- Rotate List

### Hard

- Reverse in K Groups
- Flatten Linked List
- LRU Cache
- Clone Linked List with Random Pointer
- Merge K Sorted Lists

---

# Resources

- GeeksforGeeks
- LeetCode
- HackerRank
- CodeStudio
- InterviewBit





