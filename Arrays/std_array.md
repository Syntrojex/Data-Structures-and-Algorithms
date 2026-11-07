# C++ Array (`std::array`)

`std::array` is a fixed-size container that stores elements in contiguous memory.

```cpp
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
```

## 1. Declaration and Initialization

<details>
<summary><b>Declare and Initialize</b></summary>
<br>

```cpp
array<int, 5> nums;                  // Uninitialized values
array<int, 5> nums1 = {1, 2, 3, 4, 5};
array<int, 5> nums2{1, 2, 3, 4, 5};
array<int, 5> nums3{};               // All elements = 0
```

**Time Complexity:** O(1)

</details>

## 2. Element Access

<details>
<summary><b>operator[]</b></summary>
<br>

```cpp
cout << nums[0];
nums[2] = 50;
```

- Index-based access.
- No bounds checking.

**Time Complexity:** O(1)

</details>

<details>
<summary><b>at()</b></summary>
<br>

```cpp
cout << nums.at(2);
nums.at(1) = 20;
```

- Access element using index.
- Throws an exception if index is out of range.

**Time Complexity:** O(1)

</details>

<details>
<summary><b>front() and back()</b></summary>
<br>

```cpp
cout << nums.front();  // First element
cout << nums.back();   // Last element
```

**Time Complexity:** O(1)

</details>

## 3. Size and Capacity

<details>
<summary><b>size()</b></summary>
<br>

```cpp
cout << nums.size();
```

Returns the total number of elements.

**Time Complexity:** O(1)

</details>

<details>
<summary><b>empty()</b></summary>
<br>

```cpp
if (nums.empty())
{
    cout << "Array is empty";
}
```

Checks whether the array contains zero elements.

**Time Complexity:** O(1)

</details>

## 4. Modification

<details>
<summary><b>fill()</b></summary>
<br>

```cpp
array<int, 5> nums;
nums.fill(10);
```

Fills every element with the given value.

**Time Complexity:** O(n)

</details>

## 5. Iterators and Traversal

<details>
<summary><b>begin() and end()</b></summary>
<br>

```cpp
for (auto it = nums.begin(); it != nums.end(); it++)
{
    cout << *it << " ";
}
```

- `begin()` points to the first element.
- `end()` points just after the last element.

**Time Complexity:** O(1) for each iterator operation.

</details>

<details>
<summary><b>Range-Based For Loop</b></summary>
<br>

```cpp
for (int x : nums)
{
    cout << x << " ";
}
```

Use reference when modifying elements:
<br>

```cpp
for (int &x : nums)
{
    x *= 2;
}
```

**Time Complexity:** O(n)

</details>

## 6. Useful STL Algorithms

<details>
<summary><b>sort()</b></summary>
<br>

```cpp
sort(nums.begin(), nums.end());
```

Sorts elements in ascending order.

Descending order:
<br>

```cpp
sort(nums.begin(), nums.end(), greater<int>());
```

**Time Complexity:** O(n log n)

</details>

<details>
<summary><b>reverse()</b></summary>
<br>

```cpp
reverse(nums.begin(), nums.end());
```

Reverses the elements.

**Time Complexity:** O(n)

</details>

<details>
<summary><b>find()</b></summary>
<br>

```cpp
auto it = find(nums.begin(), nums.end(), 30);

if (it != nums.end())
{
    cout << "Found";
}
```

Searches for a value.

**Time Complexity:** O(n)

</details>

<details>
<summary><b>count()</b></summary>
<br>

```cpp
int total = count(nums.begin(), nums.end(), 10);
```

Returns how many times a value appears.

**Time Complexity:** O(n)

</details>

<details>
<summary><b>min_element() and max_element()</b></summary>
<br>

```cpp
int smallest = *min_element(nums.begin(), nums.end());
int largest = *max_element(nums.begin(), nums.end());
```

Returns iterators to the smallest and largest elements.

**Time Complexity:** O(n)

</details>

<details>
<summary><b>accumulate()</b></summary>
<br>

```cpp
#include <numeric>

int sum = accumulate(nums.begin(), nums.end(), 0);
```

Calculates the sum of all elements.

**Time Complexity:** O(n)

</details>

## 7. Important Notes

- `std::array` has a fixed size.
- Its size must be known at compile time.
- Elements are stored in contiguous memory.
- Use `vector<int>` when the size needs to change.
- `sort()` and `reverse()` work directly with array iterators.
- `std::array<int, 5>` and `int arr[5]` are different types.

## 8. Complexity Cheat Sheet

| Operation | Complexity |
|---|---|
| `[]` | O(1) |
| `at()` | O(1) |
| `front()` / `back()` | O(1) |
| `size()` / `empty()` | O(1) |
| `fill()` | O(n) |
| Traversal | O(n) |
| `sort()` | O(n log n) |
| `reverse()` | O(n) |
| `find()` | O(n) |
| `count()` | O(n) |
| `min_element()` / `max_element()` | O(n) |
| `accumulate()` | O(n) |

