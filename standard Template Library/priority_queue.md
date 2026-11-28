
# `std::priority_queue`

A practical reference for the C++ `std::priority_queue`, a container adapter that uses a heap to keep the highest-priority element at the top. By default, it works as a max heap. Covers the most commonly used operations in competitive programming.

## 1. Header & Declaration

<details>
<summary><b>Declaration</b></summary>
<br>

```cpp
#include <queue>
using namespace std;

// Max Heap (default)
priority_queue<int> pq;

// Min Heap
priority_queue<int, vector<int>, greater<int>> minpq;
```

**Important:**
- Max Heap keeps the largest element at the top.
- Min Heap keeps the smallest element at the top.

</details>

## 2. Accessing Elements

<details>
<summary><b>top()</b></summary>
<br>

```cpp
pq.top();     // Returns the highest-priority element
minpq.top();  // Returns the smallest element in a min heap
```

**Important:**
- In a max heap, `top()` returns the largest element.
- In a min heap, `top()` returns the smallest element.
- `top()` does not remove the element.

</details>

## 3. Adding Elements

<details>
<summary><b>push(), emplace()</b></summary>
<br>

```cpp
pq.push(10);     // Adds 10 to the heap
pq.push(30);     // Adds 30 to the heap

pq.emplace(20);  // Constructs and adds 20
```

**Important:** After insertion, the heap automatically rearranges its elements to maintain heap order.

</details>

## 4. Removing Elements

<details>
<summary><b>pop()</b></summary>
<br>

```cpp
pq.pop();  // Removes the highest-priority element
```

**Important:**
- In a max heap, `pop()` removes the largest element.
- In a min heap, `pop()` removes the smallest element.
- `pop()` does not return the removed element.
- Use `top()` first if you need to access the element before removing it.

</details>

## 5. Size & Empty Check

<details>
<summary><b>size(), empty()</b></summary>
<br>

```cpp
pq.size();   // Returns the number of elements
pq.empty();  // Returns true if priority_queue is empty
```

</details>

## 6. Traversal & Processing

<details>
<summary><b>Processing Elements Using top() and pop()</b></summary>
<br>

```cpp
while (!pq.empty())
{
    cout << pq.top() << " ";
    pq.pop();
}
```

**Important:**
- This processes elements according to priority.
- In a max heap, elements come out in descending order.
- In a min heap, elements come out in ascending order.
- The original priority queue becomes empty after this loop.

</details>

## 7. Common Mistakes & Important Notes

- `priority_queue<int>` is a max heap by default.
- Use `priority_queue<int, vector<int>, greater<int>>` for a min heap.
- `top()` accesses the highest-priority element; it does not remove it.
- `pop()` removes the top element but does not return it.
- You cannot access elements using `[]` or normal iterators.
- A priority queue does not keep all elements fully sorted; it only guarantees the correct highest-priority element at the top.

## 8. Complexity Cheat Sheet

| Operation | Time Complexity |
|---|---|
| `top()` | O(1) |
| `push()` | O(log n) |
| `emplace()` | O(log n) |
| `pop()` | O(log n) |
| `size()` | O(1) |
| `empty()` | O(1) |

## 9. Key Takeaway

`std::priority_queue` is best when you repeatedly need to access and remove the largest or smallest element efficiently. It is commonly used to implement max heaps and min heaps.
