
# C++ List (`std::list`)

A practical reference for the built-in C++ `std::list` covering declaration, initialization, element access, insertion, deletion, size, traversal, iterators, list operations, sorting, and useful algorithms.

## 1. Header & Declaration

```cpp
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
```

<details>
<summary><b>Declaration</b></summary>
<br>

```cpp
list<int> nums;
```

- Creates an empty doubly linked list.

</details>

<details>
<summary><b>Initialization</b></summary>
<br>

```cpp
list<int> nums;                      // Empty list
list<int> nums1 = {10, 20, 30};      // Initialize with values
list<int> nums2{10, 20, 30};         // Same initialization
list<int> nums3(5);                  // Five elements initialized to 0
list<int> nums4(5, 10);             // Five elements initialized to 10
list<int> copy(nums1);              // Copy another list
```

</details>

## 2. Element Access

<details>
<summary><b>`front()` — First element</b></summary>
<br>

```cpp
cout << nums.front();
```

- Returns: Reference to the first element.
- Time: `O(1)`

</details>

<details>
<summary><b>`back()` — Last element</b></summary>
<br>

```cpp
cout << nums.back();
```

- Returns: Reference to the last element.
- Time: `O(1)`

</details>

**Important:** `std::list` does not support direct indexing using `nums[0]` or `nums.at(0)`.

## 3. Adding Elements

<details>
<summary><b>`push_front()` — Add at the beginning</b></summary>
<br>

```cpp
nums.push_front(5);
```

- Returns: `void`
- Time: `O(1)`

</details>

<details>
<summary><b>`push_back()` — Add at the end</b></summary>
<br>

```cpp
nums.push_back(40);
```

- Returns: `void`
- Time: `O(1)`

</details>

<details>
<summary><b>`emplace_front()` — Construct at the beginning</b></summary>
<br>

```cpp
nums.emplace_front(5);
```

- Constructs an element directly at the beginning.
- Returns: Reference to the inserted element.
- Time: `O(1)`

</details>

<details>
<summary><b>`emplace_back()` — Construct at the end</b></summary>
<br>

```cpp
nums.emplace_back(50);
```

- Constructs an element directly at the end.
- Returns: Reference to the inserted element.
- Time: `O(1)`

</details>

<details>
<summary><b>`insert()` — Insert at a specific position</b></summary>
<br>

```cpp
list<int> nums = {10, 20, 30};

auto it = nums.begin();
advance(it, 1);

nums.insert(it, 15);

// [10, 15, 20, 30]
```

Insert multiple copies:

```cpp
nums.insert(nums.begin(), 3, 5);
```

Insert another list's elements:

```cpp
list<int> extra = {40, 50};

nums.insert(nums.end(), extra.begin(), extra.end());
```

- Returns: Iterator to the first inserted element.
- Time: `O(1)` for insertion at a known iterator; finding the position takes `O(n)`.

</details>

## 4. Removing Elements

<details>
<summary><b>`pop_front()` — Remove first element</b></summary>
<br>

```cpp
nums.pop_front();
```

- Returns: `void`
- Time: `O(1)`

</details>

<details>
<summary><b>`pop_back()` — Remove last element</b></summary>
<br>

```cpp
nums.pop_back();
```

- Returns: `void`
- Time: `O(1)`

</details>

<details>
<summary><b>`erase()` — Remove element or range</b></summary>
<br>

```cpp
auto it = nums.begin();
advance(it, 2);

nums.erase(it);
```

Remove a range:

```cpp
auto first = nums.begin();
auto last = nums.begin();
advance(last, 3);

nums.erase(first, last);
```

- Returns: Iterator to the element after the erased element or range.
- Time: `O(1)` for one element; `O(k)` for removing k elements.

</details>

<details>
<summary><b>`remove()` — Remove all occurrences</b></summary>
<br>

```cpp
nums.remove(20);
```

- Removes all elements equal to the given value.
- Returns: `void`
- Time: `O(n)`

</details>

<details>
<summary><b>`remove_if()` — Remove elements matching a condition</b></summary>
<br>

```cpp
nums.remove_if([](int x)
{
    return x % 2 == 0;
});
```

- Removes all elements that satisfy the condition.
- Returns: `void`
- Time: `O(n)`

</details>

<details>
<summary><b>`clear()` — Remove all elements</b></summary>
<br>

```cpp
nums.clear();
```

- Removes all elements from the list.
- Returns: `void`
- Time: `O(n)`

</details>

## 5. Size & Capacity

<details>
<summary><b>`size()` — Number of elements</b></summary>
<br>

```cpp
cout << nums.size();
```

- Returns: Number of elements.
- Time: `O(1)`

</details>

<details>
<summary><b>`empty()` — Check if list is empty</b></summary>
<br>

```cpp
if (nums.empty())
{
    cout << "Empty";
}
```

- Returns: `true` or `false`.
- Time: `O(1)`

</details>

<details>
<summary><b>`max_size()` — Maximum possible size</b></summary>
<br>

```cpp
cout << nums.max_size();
```

- Returns: Theoretical maximum number of elements.
- Time: `O(1)`

</details>

## 6. Traversal

<details>
<summary><b>Range-based loop</b></summary>
<br>

```cpp
for (int x : nums)
{
    cout << x << " ";
}
```

</details>

<details>
<summary><b>Modify elements using reference</b></summary>
<br>

```cpp
for (int& x : nums)
{
    x *= 2;
}
```

</details>

<details>
<summary><b>Iterator loop</b></summary>
<br>

```cpp
for (auto it = nums.begin(); it != nums.end(); it++)
{
    cout << *it << " ";
}
```

</details>

<details>
<summary><b>Reverse traversal</b></summary>
<br>

```cpp
for (auto it = nums.rbegin(); it != nums.rend(); it++)
{
    cout << *it << " ";
}
```

</details>

## 7. Iterators

| Function | Purpose |
|---|---|
| `begin()` | Iterator to first element |
| `end()` | Iterator one position after last |
| `cbegin()` | Constant iterator to first element |
| `cend()` | Constant iterator one position after last |
| `rbegin()` | Reverse iterator to last element |
| `rend()` | Reverse iterator one position before first |
| `crbegin()` | Constant reverse iterator to last element |
| `crend()` | Constant reverse iterator one position before first |

<details>
<summary><b>`advance()` — Move iterator forward or backward</b></summary>
<br>

```cpp
auto it = nums.begin();

advance(it, 2);

cout << *it;
```

Move backward:

```cpp
advance(it, -1);
```

- Moves an iterator by the specified number of positions.
- Time: `O(n)` for n positions in a list.

</details>

<details>
<summary><b>`next()` — Get next iterator</b></summary>
<br>

```cpp
auto it = next(nums.begin(), 2);

cout << *it;
```

- Returns: Iterator advanced by the specified positions.
- Original iterator remains unchanged.
- Time: `O(n)` for n positions.

</details>

<details>
<summary><b>`prev()` — Get previous iterator</b></summary>
<br>

```cpp
auto it = prev(nums.end());

cout << *it;
```

- Returns: Iterator moved backward by the specified positions.
- Original iterator remains unchanged.
- Time: `O(n)` for n positions.

</details>

**Important:** List iterators are bidirectional. They do not support arithmetic like `it + 2` or `it - 1`.

## 8. Searching

These functions belong to `<algorithm>`, not list itself.

<details>
<summary><b>`find()` — Linear search</b></summary>
<br>

```cpp
auto it = find(nums.begin(), nums.end(), 30);

if (it != nums.end())
{
    cout << "Found";
}
```

- Returns: Iterator to first match or `end()`.
- Time: `O(n)`

</details>

<details>
<summary><b>`count()` — Count occurrences</b></summary>
<br>

```cpp
int total = count(nums.begin(), nums.end(), 10);
```

- Returns: Number of occurrences.
- Time: `O(n)`

</details>

## 9. Sorting & Rearrangement

<details>
<summary><b>`sort()` — Ascending order</b></summary>
<br>

```cpp
nums.sort();
```

- Sorts elements in ascending order.
- Time: `O(n log n)`

**Important:** Use `nums.sort()` instead of `std::sort(nums.begin(), nums.end())`.

</details>

<details>
<summary><b>Descending order</b></summary>
<br>

```cpp
nums.sort(greater<int>());
```

- Sorts elements in descending order.

</details>

<details>
<summary><b>Custom sorting</b></summary>
<br>

```cpp
nums.sort([](int a, int b)
{
    return a > b;
});
```

- Uses a custom comparison function.

</details>

<details>
<summary><b>`reverse()` — Reverse elements</b></summary>
<br>

```cpp
nums.reverse();
```

- Reverses the order of elements.
- Time: `O(n)`

</details>

<details>
<summary><b>`unique()` — Remove consecutive duplicates</b></summary>
<br>

```cpp
nums.sort();
nums.unique();
```

Example:

```cpp
// Before: [1, 1, 2, 2, 3, 3]
// After:  [1, 2, 3]
```

- Removes consecutive duplicate elements.
- Returns: `void`
- Time: `O(n)`

</details>

<details>
<summary><b>`merge()` — Merge two sorted lists</b></summary>
<br>

```cpp
list<int> a = {1, 3, 5};
list<int> b = {2, 4, 6};

a.merge(b);
```

- Merges two sorted lists into one sorted list.
- After merging, `b` becomes empty.
- Returns: `void`
- Time: `O(n + m)`

</details>

<details>
<summary><b>`splice()` — Transfer elements between lists</b></summary>
<br>

```cpp
list<int> a = {1, 2, 3};
list<int> b = {10, 20};

a.splice(a.end(), b);
```

- Transfers all elements from `b` to the end of `a`.
- `b` becomes empty.
- Returns: `void`
- Time: `O(1)` for transferring an entire list with compatible allocators.

</details>

## 10. Other Useful Functions

<details>
<summary><b>`swap()` — Exchange two lists</b></summary>
<br>

```cpp
list<int> a = {1, 2, 3};
list<int> b = {4, 5, 6};

a.swap(b);
```

- Exchanges contents of two lists.
- Time: `O(1)` under the default allocator.

</details>

<details>
<summary><b>Comparison operators</b></summary>
<br>

```cpp
a == b;
a != b;
a < b;
a > b;
a <= b;
a >= b;
```

- Compares lists lexicographically, element by element.
- Time: `O(n)` in general.

</details>

## 11. Common Mistakes & Important Notes

- `std::list` is a doubly linked list.
- Elements are not stored in contiguous memory.
- Direct indexing using `[]` is not supported.
- `at()` is not available.
- `push_front()` and `push_back()` take `O(1)`.
- Insertion and deletion at a known iterator take `O(1)`.
- Finding a position using traversal takes `O(n)`.
- `std::sort()` cannot be used with list iterators.
- Use `nums.sort()` for sorting a list.
- `unique()` removes only consecutive duplicates.
- Sort the list before `unique()` if you want to remove all duplicate values.
- `merge()` requires both lists to be sorted.
- `erase()` invalidates iterators pointing to erased elements.
- Insertion does not invalidate existing list iterators.
- Always check `empty()` before using `front()`, `back()`, `pop_front()` or `pop_back()`.
- `std::list` provides bidirectional iterators, not random-access iterators.

## 12. Complexity Cheat Sheet

| Operation | Time Complexity |
|---|---:|
| `front()`, `back()` | `O(1)` |
| `push_front()`, `push_back()` | `O(1)` |
| `emplace_front()`, `emplace_back()` | `O(1)` |
| `pop_front()`, `pop_back()` | `O(1)` |
| `insert()` at known iterator | `O(1)` |
| `erase()` at known iterator | `O(1)` |
| `remove()`, `remove_if()` | `O(n)` |
| `size()`, `empty()` | `O(1)` |
| `clear()` | `O(n)` |
| Traversal | `O(n)` |
| `find()`, `count()` | `O(n)` |
| `advance()` | `O(n)` |
| `next()`, `prev()` | `O(n)` |
| `sort()` | `O(n log n)` |
| `reverse()` | `O(n)` |
| `unique()` | `O(n)` |
| `merge()` | `O(n + m)` |
| `swap()` | `O(1)` |

## 📌 Key Takeaway

`std::list` is a built-in doubly linked list container provided by C++. It allows efficient insertion and deletion at both ends and at known iterator positions.

For working with lists, the most frequently used functions are:

`push_front()`, `push_back()`, `pop_front()`, `pop_back()`, `front()`, `back()`, `insert()`, `erase()`, `remove()`, `size()`, `empty()`, `sort()`, `reverse()`, and `unique()`.

