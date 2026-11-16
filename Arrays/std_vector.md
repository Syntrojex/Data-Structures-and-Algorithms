
# std::vector

A practical reference for the C++ `std::vector`, a dynamic array that automatically manages its size. Covers the most commonly used operations in competitive programming.

## 1. Header & Declaration

<details>
<summary><b>Declaration</b></summary>
<br>

```cpp
#include <vector>
using namespace std;

vector<int> nums;

vector<int> nums(5);        // 5 elements initialized to 0
vector<int> nums(5, 10);    // 5 elements initialized to 10
vector<int> nums = {1, 2, 3, 4, 5};
```

</details>

## 2. Element Access

<details>
<summary><b>front(), back(), [], at()</b></summary>
<br>

```cpp
nums.front();  // Returns the first element
nums.back();   // Returns the last element

nums[0];       // Accesses element at index 0
nums.at(2);    // Accesses element at index 2 with bounds checking
```

**Important:**
- `front()` returns the first element.
- `back()` returns the last element.
- `[]` does not perform bounds checking.
- `at()` checks whether the index is valid.

</details>

## 3. Adding Elements

<details>
<summary><b>push_back(), emplace_back()</b></summary>
<br>

```cpp
nums.push_back(10);       // Adds 10 at the end
nums.emplace_back(20);    // Constructs an element at the end
```

**Important:** Both add elements at the end of the vector.

</details>

## 4. Removing Elements

<details>
<summary><b>pop_back(), erase(), clear()</b></summary>
<br>

```cpp
nums.pop_back();               // Removes the last element

nums.erase(nums.begin());      // Removes the first element

nums.erase(nums.begin() + 2);  // Removes element at index 2

nums.clear();                  // Removes all elements
```

**Important:**
- `pop_back()` removes the last element.
- `erase()` removes an element using an iterator.
- `clear()` removes all elements.

</details>

## 5. Size & Empty Check

<details>
<summary><b>size(), empty(), resize()</b></summary>
<br>

```cpp
nums.size();      // Returns the number of elements
nums.empty();     // Returns true if vector is empty
nums.resize(10);  // Changes vector size to 10
```

**Important:** `size()` tells how many elements are currently present.

</details>

## 6. Traversal

<details>
<summary><b>For Loop & Range-Based Loop</b></summary>
<br>

```cpp
for (int i = 0; i < nums.size(); i++)
{
    cout << nums[i] << " ";
}

for (int x : nums)
{
    cout << x << " ";
}
```

</details>

## 7. Iterators

<details>
<summary><b>begin(), end()</b></summary>
<br>

```cpp
nums.begin();  // Iterator pointing to the first element
nums.end();    // Iterator pointing one position after the last element
```

Example:

```cpp
for (auto it = nums.begin(); it != nums.end(); it++)
{
    cout << *it << " ";
}
```

</details>

## 8. Searching & Sorting

<details>
<summary><b>find(), sort(), reverse()</b></summary>
<br>

```cpp
#include <algorithm>

auto it = find(nums.begin(), nums.end(), 10);

sort(nums.begin(), nums.end());               // Ascending order
sort(nums.begin(), nums.end(), greater<int>()); // Descending order

reverse(nums.begin(), nums.end());            // Reverses elements
```

**Important:**
- `find()` returns an iterator to the element, or `end()` if not found.
- `sort()` sorts the vector.
- `reverse()` reverses the order of elements.

</details>

## 9. Common Mistakes & Important Notes

- Accessing an invalid index using `[]` can cause undefined behavior.
- `pop_back()` does not return the removed element.
- `erase()` requires an iterator, not an index.
- Inserting or deleting elements can invalidate iterators and references.
- Inserting or deleting in the middle may require shifting elements.
- Vector stores elements contiguously in memory.

## 10. Complexity Cheat Sheet

| Operation | Time Complexity |
|---|---|
| `front()`, `back()` | O(1) |
| `[]`, `at()` | O(1) |
| `push_back()` | O(1) amortized |
| `pop_back()` | O(1) |
| `size()`, `empty()` | O(1) |
| `find()` | O(n) |
| `sort()` | O(n log n) |
| `erase()` in middle | O(n) |

## 11. Key Takeaway

`std::vector` is best when you need fast index-based access, dynamic sizing, and efficient insertion or deletion at the end.
