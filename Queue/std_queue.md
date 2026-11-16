
# `std::queue`

A practical reference for the C++ `std::queue`, a container adapter that follows the FIFO (First In, First Out) principle. The first element inserted is the first one removed. Covers commonly used operations in competitive programming.

## 1. Header & Declaration

<details>
<summary><b>Declaration</b></summary>
<br>

```cpp
#include <queue>
using namespace std;

queue<int> q;
```

</details>

## 2. Accessing Elements

<details>
<summary><b>front(), back()</b></summary>
<br>

```cpp
q.front();  // Returns the front element (first in line)
q.back();   // Returns the rear element (last in line)
```

**Important:**
- `front()` accesses the element that will be removed next.
- `back()` accesses the most recently inserted element.

</details>

## 3. Adding Elements

<details>
<summary><b>push(), emplace()</b></summary>
<br>

```cpp
q.push(10);     // Adds 10 at the rear
q.push(20);     // Adds 20 at the rear

q.emplace(30);  // Constructs and adds 30 at the rear
```

</details>

## 4. Removing Elements

<details>
<summary><b>pop()</b></summary>
<br>

```cpp
q.pop();  // Removes the front element
```

**Important:** `pop()` removes the first element inserted, but does not return it.

</details>

## 5. Size & Empty Check

<details>
<summary><b>size(), empty()</b></summary>
<br>

```cpp
q.size();   // Returns the number of elements
q.empty();  // Returns true if queue is empty
```

</details>

## 6. Processing Elements

<details>
<summary><b>Using front() and pop()</b></summary>
<br>

```cpp
while (!q.empty())
{
    cout << q.front() << " ";
    q.pop();
}
```

**Important:** This processes elements from front to rear and empties the queue.

</details>

## 7. Common Mistakes & Important Notes

- Queue follows FIFO.
- `front()` accesses the first element.
- `back()` accesses the last element.
- `pop()` removes the front element but does not return it.
- You cannot access elements using indexes.
- Queue does not support normal iterators or direct traversal.
- Always check `empty()` before accessing `front()` or `back()`.

## 8. Complexity Cheat Sheet

| Operation | Time Complexity |
|---|---|
| `front()`, `back()` | O(1) |
| `push()` | O(1) |
| `emplace()` | O(1) |
| `pop()` | O(1) |
| `size()` | O(1) |
| `empty()` | O(1) |

## 9. Key Takeaway

`std::queue` is useful for FIFO processing, especially in Breadth First Search (BFS), level order traversal, and scheduling problems.
