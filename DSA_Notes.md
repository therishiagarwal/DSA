
# Data Structures and Algorithms (DSA) Notes

## Table of Contents
1. [Introduction](#1-introduction)
2. [Time and Space Complexity](#2-time-and-space-complexity)
3. [Basic Data Structures](#3-basic-data-structures)
4. [Advanced Data Structures](#4-advanced-data-structures)
5. [Sorting Algorithms](#5-sorting-algorithms)
6. [Searching Algorithms](#6-searching-algorithms)
7. [Recursion](#7-recursion)
8. [Dynamic Programming](#8-dynamic-programming)
9. [Greedy Algorithms](#9-greedy-algorithms)
10. [Graph Algorithms](#10-graph-algorithms)
11. [Tree Algorithms](#11-tree-algorithms)
12. [Hashing](#12-hashing)
13. [Backtracking](#13-backtracking)
14. [Divide and Conquer](#14-divide-and-conquer)

---
---

## Data Structure Operations Cheat Sheet

### Time Complexity (Average and Worst Case)

| Data Structure                 | Access (Average) | Search (Average) | Insertion (Average) | Deletion (Average) | Access (Worst) | Search (Worst) | Insertion (Worst) | Deletion (Worst) |
|---------------------------------|------------------|------------------|---------------------|--------------------|----------------|----------------|-------------------|------------------|
| **Arrays**                      | O(1)             | O(n)             | O(n)                | O(n)               | O(1)           | O(n)           | O(n)              | O(n)             |
| **Stacks**                      | O(n)             | O(n)             | O(1)                | O(1)               | O(n)           | O(n)           | O(1)              | O(1)             |
| **Queues**                      | O(n)             | O(n)             | O(1)                | O(1)               | O(n)           | O(n)           | O(1)              | O(1)             |
| **Binary Trees**                | O(log n)         | O(log n)         | O(log n)            | O(log n)           | O(n)           | O(n)           | O(log n)          | O(log n)         |
| **Binary Search Trees**         | O(log n)         | O(log n)         | O(log n)            | O(log n)           | O(n)           | O(n)           | O(log n)          | O(log n)         |
| **Balanced Binary Search Trees**| O(log n)         | O(log n)         | O(log n)            | O(log n)           | O(log n)       | O(log n)       | O(log n)          | O(log n)         |
| **Hash Tables**                 | O(1)             | O(1)             | O(1)                | O(1)               | O(n)           | O(n)           | O(n)              | O(n)             |

Note: For best-case operations, the time complexities are O(1).

---

## Sorting Algorithms Cheat Sheet

### Time and Space Complexity

| Sorting Algorithm | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity | Stable? | Sorting Class |
|-------------------|------------------------|---------------------------|-------------------------|------------------|---------|---------------|
| **Bubble Sort**    | O(n)                   | O(n^2)                    | O(n^2)                  | O(1)             | Yes     | Comparison    |
| **Insertion Sort** | O(n)                   | O(n^2)                    | O(n^2)                  | O(1)             | Yes     | Comparison    |
| **Selection Sort** | O(n^2)                 | O(n^2)                    | O(n^2)                  | O(1)             | Yes     | Comparison    |
| **Merge Sort**     | O(n log n)             | O(n log n)                | O(n log n)              | O(n)             | Yes     | Comparison    |
| **Heap Sort**      | O(n log n)             | O(n log n)                | O(n log n)              | O(1)             | No      | Comparison    |
| **Quick Sort**     | O(n log n)             | O(n log n)                | O(n^2)                  | O(log n)         | No      | Comparison    |
| **Tree Sort**      | O(n log n)             | O(n log n)                | O(n^2)                  | O(n)             | Yes     | Comparison    |
| **Counting Sort**  | O(n + k)               | O(n + k)                  | O(n + k)                | O(k)             | Yes     | Linear        |
| **Bucket Sort**    | O(n + k)               | O(n + k)                  | O(n^2)                  | O(n)             | Yes     | Linear        |
| **Radix Sort**     | O(dn)                  | O(dn)                     | O(dn)                   | O(d + n)         | Yes     | Linear        |

### Remarks

- Bubble Sort is not a preferred sorting algorithm.
- In the best case (already sorted), every insertion in Insertion Sort requires constant time.
- Even a perfectly sorted array requires scanning the entire array in Selection Sort.
- Merge Sort requires O(n) space for arrays but constant space for linked lists.
- Heap Sort can achieve constant space if the input array is used as storage for the heap.
- Quick Sort can avoid the worst-case scenario by randomly selecting a pivot.
- Tree Sort involves an in-order traversal of a balanced binary search tree.
- Counting Sort and Radix Sort are linear if the range of elements is small compared to the number of elements.


## 1. Introduction
- **Data Structures** organize and store data efficiently.
- **Algorithms** are step-by-step procedures to solve a problem.

---

## 2. Time and Space Complexity

### Time Complexity
- **O(1)**: Constant time
- **O(log n)**: Logarithmic time
- **O(n)**: Linear time
- **O(n log n)**: Log-linear time
- **O(n^2)**: Quadratic time

### Space Complexity
- Similar to time complexity but measures memory usage.

---

## 3. Basic Data Structures

### Arrays
- **Definition**: Fixed-size contiguous memory blocks.
- **Time Complexity**: 
  - Access: O(1)
  - Search: O(n)
  - Insertion/Deletion: O(n)

### Linked Lists
- **Definition**: Linear collection of nodes.
- **Time Complexity**:
  - Search: O(n)
  - Insertion/Deletion: O(1) if node is known.
  
#### Pseudocode for Singly Linked List:
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
```

---

## 4. Advanced Data Structures

### Stacks
- **LIFO**: Last In, First Out.
- **Time Complexity**:
  - Push/Pop: O(1)
  
### Queues
- **FIFO**: First In, First Out.
- **Time Complexity**:
  - Enqueue/Dequeue: O(1)

---

## 5. Sorting Algorithms

### Bubble Sort
- **Time Complexity**: O(n^2)
- **Pseudo code**:
```python
def bubble_sort(arr):
    for i in range(len(arr)):
        for j in range(0, len(arr)-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
```

### Quick Sort
- **Time Complexity**: O(n log n)
- **Pseudo code**:
```python
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi-1)
        quick_sort(arr, pi+1, high)
```

---

## 6. Searching Algorithms

### Binary Search
- **Time Complexity**: O(log n)
- **Pseudo code**:
```python
def binary_search(arr, low, high, x):
    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)
    else:
        return -1
```

---

## 7. Recursion
- **Definition**: A function that calls itself.
- **Time Complexity**: Depends on the number of recursive calls and their individual time.

---

## 8. Dynamic Programming
- **Definition**: Solves problems by storing the results of subproblems to avoid redundant calculations.
- **Example Problems**: Fibonacci, Knapsack Problem.

---

## 9. Greedy Algorithms
- **Definition**: Makes a series of choices, each of which looks the best at the moment.
- **Example Problems**: Activity Selection, Huffman Coding.

---

## 10. Graph Algorithms

### Breadth First Search (BFS)
- **Time Complexity**: O(V + E)
- **Pseudo code**:
```python
def BFS(graph, start):
    visited = [False] * len(graph)
    queue = []
    queue.append(start)
    visited[start] = True

    while queue:
        s = queue.pop(0)
        print(s, end=" ")

        for i in graph[s]:
            if visited[i] == False:
                queue.append(i)
                visited[i] = True
```

### Depth First Search (DFS)
- **Time Complexity**: O(V + E)
- **Pseudo code**:
```python
def DFS(graph, v, visited):
    visited[v] = True
    print(v, end=" ")

    for neighbour in graph[v]:
        if visited[neighbour] == False:
            DFS(graph, neighbour, visited)
```

---

## 11. Tree Algorithms

### Binary Search Tree (BST)
- **Operations**:
  - Insertion: O(log n)
  - Search: O(log n)
  
### Pseudocode for Insertion in BST:
```python
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root
```

---

## 12. Hashing
- **Definition**: Technique to map keys to values using a hash function.
- **Time Complexity**: O(1) on average for insert, delete, search.

---

## 13. Backtracking
- **Definition**: Solve problems by building a solution incrementally and abandoning solutions that fail to satisfy constraints.
- **Applications**: N-Queens, Sudoku Solver, Maze solving.

---

## 14. Divide and Conquer
- **Definition**: Divide the problem into smaller subproblems, solve them recursively, and combine their results.
- **Examples**: Merge Sort, Quick Sort, Binary Search.

---
