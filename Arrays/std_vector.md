# C++ Vector (`std::vector`)

A practical reference for the built-in C++ `std::vector` covering declaration, initialization, element access, insertion, deletion, size, capacity, traversal, searching, sorting, useful algorithms, and 2D vectors.

## 1. Header & Declaration

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
```

<details>
<summary><b>Declaration</b></summary>
<br>


```cpp
vector<int> nums;
```

</details>

<details>
<summary><b>Initialization</b></summary>
<br>

```cpp
vector<int> nums;                  // Empty vector
vector<int> nums(5);               // [0, 0, 0, 0, 0]
vector<int> nums(5, 10);           // [10, 10, 10, 10, 10]
vector<int> nums = {1, 2, 3, 4};   // Initialize with values
vector<int> nums{1, 2, 3, 4};      // Same initialization
vector<int> copy(nums);            // Copy another vector
```

</details>

## 2. Element Access

<details>
<summary><b>`operator[]` — Access by index</b></summary>
<br>

```cpp
vector<int> nums = {10, 20, 30};

cout << nums[0];       // 10
nums[1] = 50;          // [10, 50, 30]
```

- Returns: Reference to the element.
- Time: `O(1)`
- No bounds checking.

</details>

<details>
<summary><b>`at()` — Bounds-checked access</b></summary>
<br>

```cpp
cout << nums.at(0);    // 10
nums.at(1) = 50;
```

- Returns: Reference to the element.
- Throws `out_of_range` if index is invalid.
- Time: `O(1)`

</details>

<details>
<summary><b>`front()` — First element</b></summary>
<br>

```cpp
cout << nums.front();
```

- Returns: First element.
- Time: `O(1)`

</details>

<details>
<summary><b>`back()` — Last element</b></summary>
<br>

```cpp
cout << nums.back();
```

- Returns: Last element.
- Time: `O(1)`

</details>

<details>
<summary><b>`data()` — Pointer to underlying array</b></summary>
<br>

```cpp
int* ptr = nums.data();

cout << ptr[0];
```

- Returns: Pointer to the first element.
- Time: `O(1)`

</details>

## 3. Adding Elements

<details>
<summary><b>`push_back()` — Add at the end</b></summary>
<br>

```cpp
nums.push_back(40);
```

- Returns: `void`
- Time: Amortized `O(1)`

</details>

<details>
<summary><b>`emplace_back()` — Construct at the end</b></summary>
<br>

```cpp
nums.emplace_back(50);
```

- Returns: Reference to the inserted element (C++17).
- Time: Amortized `O(1)`

</details>

<details>
<summary><b>`insert()` — Insert at a specific position</b></summary>
<br>

```cpp
vector<int> nums = {10, 20, 30};

nums.insert(nums.begin() + 1, 15);

// [10, 15, 20, 30]
```

Insert multiple copies:
<br>

```cpp
nums.insert(nums.begin(), 3, 5);
```

Insert another vector:
<br>

```cpp
vector<int> extra = {40, 50};

nums.insert(nums.end(), extra.begin(), extra.end());
```

- Returns: Iterator to the first inserted element.
- Time: `O(n)` for middle/start insertion.

</details>

## 4. Removing Elements

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
nums.erase(nums.begin());              // Remove first element
nums.erase(nums.begin() + 2);          // Remove element at index 2
nums.erase(nums.begin(), nums.begin() + 2); // Remove first two elements
```

- Returns: Iterator to the next element.
- Time: `O(n)` in general.

</details>

<details>
<summary><b>`clear()` — Remove all elements</b></summary>
<br>

```cpp
nums.clear();
```

- Returns: `void`
- Time: `O(n)`
- Sets size to zero; capacity remains unchanged.

</details>

<details>
<summary><b>`std::erase()` — Remove all occurrences (C++20)</b></summary>
<br>

```cpp
erase(nums, 20);
```

- Returns: Number of elements removed.
- Time: `O(n)`

</details>

<details>
<summary><b>`std::erase_if()` — Remove elements matching a condition (C++20)</b></summary>
<br>

```cpp
erase_if(nums, [](int x)
{
    return x % 2 == 0;
});
```

- Returns: Number of elements removed.
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
<summary><b>`empty()` — Check if vector is empty</b></summary>
<br>

```cpp
if (nums.empty())
    cout << "Empty";
```

- Returns: `true` or `false`.
- Time: `O(1)`

</details>

<details>
<summary><b>`capacity()` — Allocated capacity</b></summary>
<br>

```cpp
cout << nums.capacity();
```

- Returns: Number of elements that can fit without reallocation.
- Time: `O(1)`

</details>

<details>
<summary><b>`max_size()` — Maximum possible size</b></summary>
<br>

```cpp
cout << nums.max_size();
```

- Returns: Theoretical maximum number of elements.

</details>

<details>
<summary><b>`reserve()` — Allocate capacity</b></summary>
<br>

```cpp
nums.reserve(100);
```

- Reserves at least the requested capacity.
- Does not change size.
- Time: `O(n)` if reallocation occurs.

</details>

<details>
<summary><b>`resize()` — Change vector size</b></summary>
<br>

```cpp
nums.resize(5);        // Add/remove elements to make size 5
nums.resize(10, 7);    // New elements initialized with 7
```

- Changes the actual number of elements.
- Time: `O(n)` in the number of elements added or removed.

</details>

<details>
<summary><b>`shrink_to_fit()` — Request reduced capacity</b></summary>
<br>

```cpp
nums.shrink_to_fit();
```

- Requests capacity reduction to fit the current size.
- Not guaranteed to reduce capacity.

</details>

## 6. Traversal

<details>
<summary><b>Index-based loop</b></summary>
<br>

```cpp
for (int i = 0; i < nums.size(); i++)
{
    cout << nums[i] << " ";
}
```

</details>

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

Example:

```cpp
auto it = nums.begin();

cout << *it;       // First element
cout << *(it + 2); // Third element
```

## 8. Searching

These functions belong to `<algorithm>`, not vector itself.

<details>
<summary><b>`find()` — Linear search</b></summary>


```cpp
auto it = find(nums.begin(), nums.end(), 30);

if (it != nums.end())
    cout << "Found at index: " << it - nums.begin();
```

- Returns: Iterator to first match or `end()`.
- Time: `O(n)`

</details>

<details>
<summary><b>`binary_search()` — Search in sorted vector</b></summary>


```cpp
bool found = binary_search(nums.begin(), nums.end(), 30);
```

- Returns: `true` or `false`.
- Time: `O(log n)`

</details>

<details>
<summary><b>`lower_bound()` — First element greater than or equal to value</b></summary>


```cpp
auto it = lower_bound(nums.begin(), nums.end(), 30);

int index = it - nums.begin();
```

- Requires sorted vector.
- Time: `O(log n)`

</details>

<details>
<summary><b>`upper_bound()` — First element greater than value</b></summary>


```cpp
auto it = upper_bound(nums.begin(), nums.end(), 30);

int index = it - nums.begin();
```

- Requires sorted vector.
- Time: `O(log n)`

</details>

## 9. Counting & Aggregates

<details>
<summary><b>`count()` — Count occurrences</b></summary>


```cpp
int total = count(nums.begin(), nums.end(), 10);
```

- Returns: Number of occurrences.
- Time: `O(n)`

</details>

<details>
<summary><b>`count_if()` — Count matching elements</b></summary>


```cpp
int total = count_if(nums.begin(), nums.end(), [](int x)
{
    return x % 2 == 0;
});
```

- Returns: Number of matching elements.
- Time: `O(n)`

</details>

<details>
<summary><b>`min_element()` — Find minimum element</b></summary>


```cpp
int mn = *min_element(nums.begin(), nums.end());
```

- Returns: Iterator to minimum element.
- Time: `O(n)`

</details>

<details>
<summary><b>`max_element()` — Find maximum element</b></summary>


```cpp
int mx = *max_element(nums.begin(), nums.end());
```

- Returns: Iterator to maximum element.
- Time: `O(n)`

</details>

<details>
<summary><b>`accumulate()` — Calculate sum</b></summary>


```cpp
int sum = accumulate(nums.begin(), nums.end(), 0);
```

For large sums:

```cpp
long long sum = accumulate(nums.begin(), nums.end(), 0LL);
```

- Returns: Sum of elements.
- Time: `O(n)`

</details>

## 10. Sorting & Rearrangement

<details>
<summary><b>`sort()` — Ascending order</b></summary>


```cpp
sort(nums.begin(), nums.end());
```

- Time: `O(n log n)`

</details>

<details>
<summary><b>Descending order</b></summary>


```cpp
sort(nums.begin(), nums.end(), greater<int>());
```

</details>

<details>
<summary><b>Custom sorting</b></summary>


```cpp
sort(nums.begin(), nums.end(), [](int a, int b)
{
    return a > b;
});
```

</details>

<details>
<summary><b>`reverse()` — Reverse elements</b></summary>


```cpp
reverse(nums.begin(), nums.end());
```

- Time: `O(n)`

</details>

<details>
<summary><b>`rotate()` — Rotate elements</b></summary>


```cpp
rotate(nums.begin(), nums.begin() + 2, nums.end());
```

Rotates left by 2 positions.

- Time: `O(n)`

</details>

<details>
<summary><b>`unique()` — Remove consecutive duplicates</b></summary>


```cpp
nums.erase(unique(nums.begin(), nums.end()), nums.end());
```

Sort first if you want to remove all duplicate values.

- Time: `O(n)` for `unique()`.

</details>

<details>
<summary><b>`remove()` — Remove matching values</b></summary>


```cpp
nums.erase(remove(nums.begin(), nums.end(), 10), nums.end());
```

- Time: `O(n)`

</details>

<details>
<summary><b>`fill()` — Set all elements to a value</b></summary>


```cpp
fill(nums.begin(), nums.end(), 0);
```

- Time: `O(n)`

</details>

<details>
<summary><b>`iota()` — Fill with consecutive values</b></summary>


```cpp
iota(nums.begin(), nums.end(), 1);
```

Example result:

```cpp
// [1, 2, 3, 4, 5]
```

- Time: `O(n)`
- Requires `<numeric>`.

</details>

## 11. Other Useful Functions

<details>
<summary><b>`swap()` — Exchange two vectors</b></summary>


```cpp
vector<int> a = {1, 2, 3};
vector<int> b = {4, 5, 6};

a.swap(b);
```

- Exchanges contents.
- Time: `O(1)` under the default allocator.

</details>

<details>
<summary><b>Comparison operators</b></summary>


```cpp
a == b;
a != b;
a < b;
a > b;
a <= b;
a >= b;
```

Compares vectors lexicographically, element by element.

- Time: `O(n)` in general.

</details>

## 12. 2D Vectors

A 2D vector is a vector containing other vectors.

<details>
<summary><b>Declaration</b></summary>


```cpp
vector<vector<int>> grid;
```

</details>

<details>
<summary><b>Initialization</b></summary>


```cpp
vector<vector<int>> grid(3, vector<int>(4, 0));
```

Creates 3 rows and 4 columns filled with zeros.

</details>

<details>
<summary><b>Access elements</b></summary>


```cpp
grid[0][0] = 10;
grid[1][2] = 20;

cout << grid[1][2];
```

</details>

<details>
<summary><b>Get dimensions</b></summary>


```cpp
int rows = grid.size();
int cols = grid[0].size();
```

</details>

<details>
<summary><b>Traversal</b></summary>


```cpp
for (int i = 0; i < grid.size(); i++)
{
    for (int j = 0; j < grid[i].size(); j++)
    {
        cout << grid[i][j] << " ";
    }

    cout << endl;
}
```

</details>

<details>
<summary><b>Range-based traversal</b></summary>


```cpp
for (auto& row : grid)
{
    for (int x : row)
    {
        cout << x << " ";
    }

    cout << endl;
}
```

</details>

## 13. Common Mistakes & Important Notes

- `vector<int> nums(5, 1)` creates five elements containing `1`.
- `vector<int> nums{5, 1}` creates two elements: `5` and `1`.
- `nums.size()` returns an unsigned value.
- Accessing an invalid index using `[]` causes undefined behavior.
- Always check `empty()` before using `front()`, `back()` or `pop_back()`.
- `reserve()` changes capacity, not size.
- `resize()` changes the actual number of elements.
- `remove()` and `unique()` do not directly reduce vector size; use `erase()`.
- `binary_search()`, `lower_bound()` and `upper_bound()` require sorted data.
- `push_back()` can invalidate existing iterators and references if reallocation occurs.
- Passing a vector by value creates a copy; use `const vector<int>&` when only reading it.
- `for (auto x : nums)` copies elements; use `auto&` to modify them or `const auto&` to read without copying.

## 14. Complexity Cheat Sheet

| Operation | Time Complexity |
|---|---:|
| `nums[i]`, `at()` | `O(1)` |
| `front()`, `back()` | `O(1)` |
| `size()`, `empty()`, `capacity()` | `O(1)` |
| `push_back()`, `emplace_back()` | `O(1)` amortized |
| `pop_back()` | `O(1)` |
| `insert()` | `O(n)` |
| `erase()` | `O(n)` |
| `clear()` | `O(n)` |
| `reserve()` | `O(n)` if reallocating |
| `resize()` | `O(n)` in changes |
| `find()`, `count()` | `O(n)` |
| `binary_search()` | `O(log n)` |
| `lower_bound()`, `upper_bound()` | `O(log n)` |
| `min_element()`, `max_element()` | `O(n)` |
| `accumulate()` | `O(n)` |
| `sort()` | `O(n log n)` |
| `reverse()`, `rotate()` | `O(n)` |
| `unique()`, `remove()` | `O(n)` |
| `fill()`, `iota()` | `O(n)` |
| `swap()` | `O(1)` |

## 📌 Key Takeaway

`std::vector` is a built-in dynamic array provided by C++. It automatically manages memory and provides convenient functions for inserting, deleting, accessing, searching, and sorting elements.

For DSA, the most frequently used functions are:

`push_back()`, `pop_back()`, `size()`, `empty()`, `insert()`, `erase()`, `sort()`, `find()`, `reverse()`, `front()`, `back()`, and `resize()`.
