# `std::list`

A practical reference for the C++ `std::list`, a doubly linked list in which each node connects to both the previous and next node. Covers the most commonly used operations in competitive programming.

## 1. Header & Declaration

<details>
<summary><b>Declaration</b></summary>
<br>

```cpp
#include <list>
using namespace std;

list<int> nums;

list<int> nums = {10, 20, 30, 40};
```

</details>

## 2. Element Access

<details>
<summary><b>front(), back()</b></summary>
<br>

```cpp
nums.front();  // Returns the value stored in the head node
nums.back();   // Returns the value stored in the tail node
```

**Important:**
- `front()` accesses the head node's value.
- `back()` accesses the tail node's value.
- `std::list` does not support `[]` or `at()` because it is not an array.

</details>

## 3. Adding Elements

<details>
<summary><b>push_front(), push_back()</b></summary>
<br>

```cpp
nums.push_front(5);   // Adds 5 at the head
nums.push_back(50);   // Adds 50 at the tail
```

</details>

## 4. Removing Elements

<details>
<summary><b>pop_front(), pop_back(), remove(), erase()</b></summary>
<br>

```cpp
nums.pop_front();       // Removes the head node
nums.pop_back();        // Removes the tail node

nums.remove(20);        // Removes all nodes containing 20

nums.erase(nums.begin()); // Removes the first node

nums.clear();           // Removes all nodes
```

**Important:**
- `pop_front()` removes the head node.
- `pop_back()` removes the tail node.
- `remove(value)` removes every occurrence of that value.
- `erase()` removes a node using an iterator.

</details>

## 5. Size & Empty Check

<details>
<summary><b>size(), empty()</b></summary>
<br>

```cpp
nums.size();   // Returns the number of nodes
nums.empty();  // Returns true if list is empty
```

</details>

## 6. Traversal

<details>
<summary><b>Range-Based Loop & Iterators</b></summary>
<br>

```cpp
for (int x : nums)
{
    cout << x << " ";
}

for (auto it = nums.begin(); it != nums.end(); it++)
{
    cout << *it << " ";
}
```

**Important:** A list does not support direct index-based traversal.

</details>

## 7. Iterators

<details>
<summary><b>begin(), end(), rbegin(), rend()</b></summary>
<br>

```cpp
nums.begin();   // Iterator pointing to the head node
nums.end();     // Iterator pointing after the tail node

nums.rbegin();  // Reverse iterator pointing to the tail node
nums.rend();    // Reverse iterator pointing before the head node
```

Example:

```cpp
for (auto it = nums.rbegin(); it != nums.rend(); it++)
{
    cout << *it << " ";
}
```

**Important:** `std::list` supports bidirectional iterators, so you can move forward and backward.

</details>

## 8. Searching & Sorting

<details>
<summary><b>find(), sort(), reverse()</b></summary>
<br>

```cpp
#include <algorithm>

auto it = find(nums.begin(), nums.end(), 20);

nums.sort();      // Sorts in ascending order
nums.reverse();   // Reverses the list
```

**Important:**
- `find()` returns an iterator to the element, or `end()` if not found.
- Use `nums.sort()` instead of `std::sort()`.
- `std::sort()` does not work with list iterators.

</details>

## 9. Common Mistakes & Important Notes

- `std::list` is a doubly linked list, not a singly linked list.
- `front()` returns the head node's value; `back()` returns the tail node's value.
- No direct index access using `[]` or `at()`.
- Use iterators to access or erase specific nodes.
- Insertion does not invalidate existing iterators.
- Erasing a node invalidates iterators pointing to that erased node.
- Insertion and deletion at the beginning or end take O(1) time.

## 10. Complexity Cheat Sheet

| Operation | Time Complexity |
|---|---|
| `front()`, `back()` | O(1) |
| `push_front()`, `push_back()` | O(1) |
| `pop_front()`, `pop_back()` | O(1) |
| `size()`, `empty()` | O(1) |
| `remove(value)` | O(n) |
| `find()` | O(n) |
| `sort()` | O(n log n) |
| `reverse()` | O(n) |
| `erase(iterator)` | O(1) |

## 11. Key Takeaway

`std::list` is useful when frequent insertion and deletion at known positions are required. It does not provide fast index-based access.
