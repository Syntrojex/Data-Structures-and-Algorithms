
# `std::forward_list`

A practical reference for the C++ `std::forward_list`, a singly linked list in which each node points only to the next node. Covers the most commonly used operations in competitive programming.

## 1. Header & Declaration

<details>
<summary><b>Declaration</b></summary>
<br>

```cpp
#include <forward_list>
using namespace std;

forward_list<int> nums;

forward_list<int> nums = {10, 20, 30, 40};
```

</details>

## 2. Element Access

<details>
<summary><b>front()</b></summary>
<br>

```cpp
nums.front();  // Returns the value stored in the head node
```

**Important:**
- `front()` accesses the head node's value.
- `forward_list` does not have `back()`, `[]`, or `at()`.
- It only provides forward movement from one node to the next.

</details>

## 3. Adding Elements

<details>
<summary><b>push_front(), insert_after()</b></summary>
<br>

```cpp
nums.push_front(5);  // Adds 5 at the head

auto it = nums.begin();

nums.insert_after(it, 15); // Adds 15 after the node pointed to by it
```

**Important:**
- `push_front()` inserts a new node at the head.
- `insert_after()` inserts a new node after a given position.
- There is no `push_back()` in `forward_list`.

</details>

## 4. Removing Elements

<details>
<summary><b>pop_front(), erase_after(), remove(), clear()</b></summary>
<br>

```cpp
nums.pop_front();       // Removes the head node

auto it = nums.begin();

nums.erase_after(it);   // Removes the node after it

nums.remove(20);        // Removes all nodes containing 20

nums.clear();           // Removes all nodes
```

**Important:**
- `pop_front()` removes the head node.
- `erase_after()` removes the node after a given iterator.
- `remove(value)` removes all nodes containing that value.
- There is no `pop_back()`.

</details>

## 5. Empty Check

<details>
<summary><b>empty()</b></summary>
<br>

```cpp
nums.empty();  // Returns true if forward_list is empty
```

**Important:** `forward_list` does not provide `size()`. If you need the number of nodes, you must count them manually.

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

**Important:** Traversal is only forward, from the head node towards the last node.

</details>

## 7. Iterators

<details>
<summary><b>begin(), end(), before_begin()</b></summary>
<br>

```cpp
nums.begin();         // Iterator pointing to the head node
nums.end();           // Iterator pointing after the last node
nums.before_begin();  // Iterator pointing before the head node
```

**Important:** `before_begin()` is useful with `insert_after()` and `erase_after()` when working at the head of the list.

</details>

## 8. Searching & Sorting

<details>
<summary><b>find(), sort(), reverse()</b></summary>
<br>

```cpp
#include <algorithm>

auto it = find(nums.begin(), nums.end(), 20);

nums.sort();       // Sorts in ascending order
nums.reverse();    // Reverses the list
```

**Important:**
- `find()` returns an iterator to the element, or `end()` if not found.
- Use `nums.sort()` instead of `std::sort()`.
- `std::sort()` does not work with forward_list iterators.

</details>

## 9. Common Mistakes & Important Notes

- `forward_list` is a singly linked list.
- Each node points only to the next node.
- `front()` accesses the head node's value.
- No `back()`, `[]`, `at()`, `push_back()`, or `pop_back()`.
- No `size()` function.
- Use `insert_after()` instead of `insert()`.
- Use `erase_after()` instead of `erase()`.
- Only forward traversal is supported.

## 10. Complexity Cheat Sheet

| Operation | Time Complexity |
|---|---|
| `front()` | O(1) |
| `push_front()` | O(1) |
| `pop_front()` | O(1) |
| `insert_after()` | O(1) |
| `erase_after()` | O(1) |
| `remove(value)` | O(n) |
| `find()` | O(n) |
| `sort()` | O(n log n) |
| `reverse()` | O(n) |
| `empty()` | O(1) |

## 11. Key Takeaway

`std::forward_list` is useful when you need a lightweight singly linked list with efficient insertion and deletion at the beginning or after a known node.
