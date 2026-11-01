<h1 align="center">C++ Vector (std::vector)</h1>

A complete **function reference for `std::vector` in C++** covering constructors, element access, iterators, capacity, insertion, deletion, searching, sorting, rearrangement, 2D vectors, `vector<bool>`, iterator invalidation, and the most common pitfalls — with syntax, return values, complexity, and examples for every function.

## 📌 Overview

A `vector` is a **dynamic array**: it stores elements in **contiguous memory** and grows automatically when it runs out of space. It keeps `size` (elements actually stored) separate from `capacity` (memory currently allocated), exactly like a hand-written dynamic array that calls `regrow()` when full.

```text
size = 3, capacity = 4

Index:    0     1     2     3
vector: [ 10  |  20  |  30  |  _  ]
                              ↑
                        unused slot (capacity - size)
```

```text
push_back when size == capacity  →  allocate bigger block, move elements over, free old block
```

```cpp
#include <vector>      // std::vector
#include <algorithm>   // sort, find, reverse, unique, ...
#include <numeric>     // accumulate, iota
using namespace std;
```

The core examples below were compiled and run with `g++ -std=c++20`. Functions that need a newer standard are marked **(C++17)**, **(C++20)**, or **(C++23)** — the C++23 ones are documented from the standard and were not run here.

---

# 1. Vector Structure

```cpp
template <class T, class Allocator = std::allocator<T>>
class vector;
```

- `T` → type of each element (`int`, `string`, another `vector`, ...)
- `Allocator` → memory allocator (almost always left as the default)

Conceptually, a vector holds three things:

```cpp
T*     data;       // pointer to the heap block
size_t size;       // number of stored elements
size_t capacity;   // number of elements the block can hold
```

### Member Types

| Type | Meaning |
|---|---|
| `value_type` | `T` |
| `size_type` | unsigned integer type (usually `size_t`) |
| `reference` / `const_reference` | `T&` / `const T&` |
| `iterator` / `const_iterator` | random-access iterators |
| `reverse_iterator` | iterator that walks backwards |

---

# 2. Constructors, Assignment & Destructor

<details>
<summary><b>Default Constructor</b> — Empty vector</summary>

### Syntax

```cpp
vector<int> a;
```

### Result

`size = 0`, `capacity = 0`, no heap memory allocated.

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>Fill Constructor (size only)</b> — n default-initialized elements</summary>

### Syntax

```cpp
explicit vector(size_type n);
```

### Example

```cpp
vector<int> b(5);     // [0, 0, 0, 0, 0]  (value-initialized)
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>Fill Constructor (size + value)</b> — n copies of a value</summary>

### Syntax

```cpp
vector(size_type n, const T& value);
```

### Example

```cpp
vector<int> c(5, 7);  // [7, 7, 7, 7, 7]
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>Initializer-List Constructor</b> — Create with known values</summary>

### Syntax

```cpp
vector(initializer_list<T> list);
```

### Example

```cpp
vector<int> d = {1, 2, 3, 4, 5};
vector<int> d2{1, 2, 3};          // same idea
vector v{1, 2, 3};                // (C++17) type deduced as vector<int>
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>Range Constructor</b> — Copy from any iterator range</summary>

### Syntax

```cpp
template <class InputIt>
vector(InputIt first, InputIt last);
```

### Example

```cpp
vector<int> d = {1, 2, 3, 4, 5};
vector<int> e(d.begin() + 1, d.begin() + 4);   // [2, 3, 4]
```

The range is `[first, last)` — `last` is **not** included.

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>Copy Constructor</b> — Deep copy</summary>

### Syntax

```cpp
vector(const vector& other);
```

### Example

```cpp
vector<int> f(d);     // f is an independent copy of d
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>Move Constructor</b> — Steal the buffer</summary>

### Syntax

```cpp
vector(vector&& other) noexcept;
```

### Example

```cpp
vector<int> g(std::move(f));   // g owns f's buffer, f becomes empty
```

After the move, the source is valid but its contents are unspecified (in practice, empty).

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>operator=</b> — Assignment</summary>

### Syntax

```cpp
vector& operator=(const vector& other);          // copy assignment
vector& operator=(vector&& other) noexcept;      // move assignment
vector& operator=(initializer_list<T> list);     // from a braced list
```

### Returns

Reference to `*this`.

### Example

```cpp
vector<int> x = {1, 2, 3};
vector<int> y;
y = x;            // deep copy
y = {9, 8};       // replaces contents
```

### Complexity

- Copy / list: `O(n)`
- Move: `O(1)`

</details>

---

<details>
<summary><b>Destructor</b> — Automatic cleanup</summary>

### Syntax

```cpp
~vector();
```

Destroys every element and frees the heap block automatically when the vector goes out of scope. No manual `delete[]` is ever needed.

### Complexity

- Time: `O(n)`

</details>

---

# 3. Element Access

<details>
<summary><b>operator[]</b> — Access by index (no bounds check)</summary>

### Syntax

```cpp
reference       operator[](size_type i);
const_reference operator[](size_type i) const;
```

### Returns

A reference to the element at index `i` — so it can be read **and** modified.

### Example

```cpp
vector<int> d = {1, 2, 3, 4, 5};
d[0] = 100;
cout << d[0];     // 100
```

### Warning

Out-of-range index is **undefined behavior** — no exception, no check.

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>at()</b> — Access by index (bounds-checked)</summary>

### Syntax

```cpp
reference       at(size_type i);
const_reference at(size_type i) const;
```

### Returns

A reference to the element at index `i`.

### Throws

`std::out_of_range` if `i >= size()`.

### Example

```cpp
try {
    d.at(10);
} catch (const out_of_range& ex) {
    cout << "out_of_range caught";
}
```

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>front()</b> — First element</summary>

### Syntax

```cpp
reference       front();
const_reference front() const;
```

### Returns

Reference to the first element. Calling it on an **empty** vector is undefined behavior.

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>back()</b> — Last element</summary>

### Syntax

```cpp
reference       back();
const_reference back() const;
```

### Returns

Reference to the last element. Calling it on an **empty** vector is undefined behavior.

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>data()</b> — Raw pointer to the underlying array</summary>

### Syntax

```cpp
T*       data() noexcept;
const T* data() const noexcept;
```

### Returns

Pointer to the first element of the contiguous block. Useful for passing a vector to C APIs.

### Example

```cpp
vector<int> d = {1, 2, 3};
int* p = d.data();
cout << *p << p[2];     // 1 and 3
```

### Complexity

- Time: `O(1)`

</details>

---

# 4. Iterators

An iterator is a pointer-like object that points to an element. Vector iterators are **random-access**, so `it + 3`, `it - 1`, `it2 - it1`, and `it[2]` all work.

<details>
<summary><b>begin() / end()</b> — Forward iterators</summary>

### Syntax

```cpp
iterator begin();     iterator end();
```

### Returns

- `begin()` → iterator to the first element
- `end()` → iterator **one past** the last element (never dereference it)

### Example

```cpp
for (auto it = d.begin(); it != d.end(); ++it)
    cout << *it << " ";
```

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>cbegin() / cend()</b> — Const forward iterators</summary>

### Syntax

```cpp
const_iterator cbegin() const noexcept;
const_iterator cend() const noexcept;
```

Same as `begin()` / `end()` but the elements cannot be modified through the iterator.

</details>

---

<details>
<summary><b>rbegin() / rend()</b> — Reverse iterators</summary>

### Syntax

```cpp
reverse_iterator rbegin();    reverse_iterator rend();
```

### Returns

- `rbegin()` → points to the **last** element
- `rend()` → one before the **first** element

### Example

```cpp
vector<int> it = {1, 2, 3};
for (auto x = it.rbegin(); x != it.rend(); ++x)
    cout << *x << " ";          // 3 2 1
```

`crbegin()` / `crend()` are the const versions.

</details>

---

# 5. Capacity

<details>
<summary><b>size()</b> — Number of elements</summary>

### Syntax

```cpp
size_type size() const noexcept;
```

### Returns

Number of elements currently stored (an **unsigned** value).

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>empty()</b> — Check for no elements</summary>

### Syntax

```cpp
bool empty() const noexcept;
```

### Returns

`true` if `size() == 0`, otherwise `false`. Prefer `v.empty()` over `v.size() == 0`.

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>capacity()</b> — Allocated slots</summary>

### Syntax

```cpp
size_type capacity() const noexcept;
```

### Returns

How many elements the vector can hold **before it must reallocate**.

### Growth Example (GCC)

```text
push_back 20 times:  capacity  1 → 2 → 4 → 8 → 16 → 32
```

The exact growth factor is implementation-defined (commonly **2×** on GCC/Clang, **1.5×** on MSVC), but `push_back` is guaranteed **amortized `O(1)`**.

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>max_size()</b> — Theoretical maximum</summary>

### Syntax

```cpp
size_type max_size() const noexcept;
```

### Returns

The largest number of elements the vector could ever hold on this system (a huge number; rarely useful in practice).

</details>

---

<details>
<summary><b>reserve(n)</b> — Pre-allocate capacity</summary>

### Syntax

```cpp
void reserve(size_type n);
```

### Behavior

If `n > capacity()`, allocates space for at least `n` elements. It **never shrinks** and **never changes `size()`**.

### Throws

`std::length_error` if `n > max_size()`.

### Example

```cpp
vector<int> r;
r.reserve(100);
// size = 0, capacity = 100
```

Use it when you know the final size in advance — it avoids repeated reallocations.

### Complexity

- Time: `O(n)` when it reallocates, otherwise `O(1)`

</details>

---

<details>
<summary><b>shrink_to_fit()</b> — Release unused capacity</summary>

### Syntax

```cpp
void shrink_to_fit();
```

### Behavior

A **non-binding request** to reduce `capacity()` down to `size()`.

### Example

```cpp
r.push_back(1);
r.shrink_to_fit();
// capacity = 1
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>resize(n) / resize(n, value)</b> — Change the number of elements</summary>

### Syntax

```cpp
void resize(size_type n);
void resize(size_type n, const T& value);
```

### Behavior

- `n < size()` → extra elements at the end are destroyed
- `n > size()` → new elements are appended (default-initialized, or copies of `value`)
- `n == size()` → nothing happens

### Example

```cpp
vector<int> rs = {1, 2, 3};
rs.resize(5);        // [1, 2, 3, 0, 0]
rs.resize(2);        // [1, 2]
rs.resize(4, 9);     // [1, 2, 9, 9]
```

Note: `resize` changes **size**; `reserve` changes **capacity**.

### Complexity

- Time: `O(n)` in the number of elements added or removed

</details>

---

# 6. Insertion

<details>
<summary><b>push_back(value)</b> — Add at the end</summary>

### Syntax

```cpp
void push_back(const T& value);
void push_back(T&& value);
```

### Returns

Nothing (`void`).

### Example

```cpp
vector<int> m = {10, 20, 30};
m.push_back(40);          // [10, 20, 30, 40]
```

### Complexity

- Amortized: `O(1)`
- Worst case: `O(n)` when a reallocation happens

</details>

---

<details>
<summary><b>emplace_back(args...)</b> — Construct directly at the end</summary>

### Syntax

```cpp
template <class... Args>
reference emplace_back(Args&&... args);     // returns reference since C++17
```

### Returns

A reference to the new element **(C++17)**; `void` before C++17.

### Example

```cpp
vector<pair<int,string>> p;
p.emplace_back(1, "ali");      // builds the pair in place, no temporary
```

Same cost as `push_back`, but avoids creating a temporary object when the element type has a multi-argument constructor.

### Complexity

- Amortized: `O(1)`

</details>

---

<details>
<summary><b>insert(pos, ...)</b> — Insert anywhere</summary>

### Syntax

```cpp
iterator insert(const_iterator pos, const T& value);                       // one value
iterator insert(const_iterator pos, size_type n, const T& value);          // n copies
template <class InputIt>
iterator insert(const_iterator pos, InputIt first, InputIt last);          // a range
iterator insert(const_iterator pos, initializer_list<T> list);             // a braced list
```

### Returns

An iterator pointing to the **first inserted element** (or `pos` if nothing was inserted).

### Example

```cpp
vector<int> m = {10, 20, 30, 40, 50};
m.insert(m.begin() + 1, 15);            // [10, 15, 20, 30, 40, 50]
m.insert(m.begin(), 2, 0);              // [0, 0, 10, 15, 20, ...]
vector<int> extra = {7, 8};
m.insert(m.end(), extra.begin(), extra.end());   // appends 7, 8
m.insert(m.begin(), {100, 200});        // [100, 200, 0, 0, ...]
```

Elements from `pos` onward are shifted right, just like `shiftRight()` in a hand-written array.

### Complexity

- Time: `O(n)` (shifting + number of inserted elements)

</details>

---

<details>
<summary><b>emplace(pos, args...)</b> — Construct in place at a position</summary>

### Syntax

```cpp
template <class... Args>
iterator emplace(const_iterator pos, Args&&... args);
```

### Returns

Iterator to the newly constructed element.

### Example

```cpp
m.emplace(m.begin() + 2, 55);     // inserts 55 at index 2
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>append_range() / insert_range()</b> — Insert a whole range <i>(C++23)</i></summary>

### Syntax

```cpp
template <class R> void append_range(R&& rg);                         // add range at the end
template <class R> iterator insert_range(const_iterator pos, R&& rg); // add range at pos
```

Work with any range (another vector, `std::array`, a view, ...). Only available with `-std=c++23` and a compiler/library that implements them.

</details>

---

# 7. Deletion

<details>
<summary><b>pop_back()</b> — Remove the last element</summary>

### Syntax

```cpp
void pop_back();
```

### Returns

Nothing (`void`). Calling it on an **empty** vector is undefined behavior — check `empty()` first.

### Example

```cpp
m.pop_back();      // removes the last value
```

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>erase()</b> — Remove one element or a range</summary>

### Syntax

```cpp
iterator erase(const_iterator pos);                         // one element
iterator erase(const_iterator first, const_iterator last);  // range [first, last)
```

### Returns

An iterator to the element **right after** the last removed one (`end()` if none).

### Example

```cpp
vector<int> m = {100, 200, 55, 0, 0, 10};
auto it = m.erase(m.begin());                 // removes 100, *it == 200
auto it2 = m.erase(m.begin(), m.begin() + 2); // removes 200 and 55, *it2 == 0
```

Elements after the erased part are shifted left, like `shiftLeft()`.

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>clear()</b> — Remove everything</summary>

### Syntax

```cpp
void clear() noexcept;
```

### Behavior

Sets `size()` to `0`. The **capacity stays the same** (memory is not released). Use `shrink_to_fit()` afterwards if you want the memory back.

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>Erase-Remove Idiom</b> — Delete all elements equal to a value</summary>

`std::remove` does **not** actually shrink the vector — it shifts the kept elements forward and returns the new logical end. You then `erase` the leftover tail.

### Syntax

```cpp
v.erase(remove(v.begin(), v.end(), value), v.end());
v.erase(remove_if(v.begin(), v.end(), predicate), v.end());
```

### Example

```cpp
vector<int> er = {1, 2, 3, 2, 4, 2};
er.erase(remove(er.begin(), er.end(), 2), er.end());   // [1, 3, 4]
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>std::erase() / std::erase_if()</b> — One-line cleanup <i>(C++20)</i></summary>

### Syntax

```cpp
size_type erase(vector<T>& v, const U& value);
size_type erase_if(vector<T>& v, Predicate pred);
```

### Returns

The **number of elements removed**.

### Example

```cpp
vector<int> v1 = {1, 2, 3, 2, 4, 2};
auto n1 = erase(v1, 2);                  // n1 = 3, v1 = [1, 3, 4]

vector<int> v2 = {1, 2, 3, 4, 5, 6};
auto n2 = erase_if(v2, [](int x) { return x % 2 == 0; });   // n2 = 3, v2 = [1, 3, 5]
```

### Complexity

- Time: `O(n)`

</details>

---

# 8. Assign, Swap & Comparison

<details>
<summary><b>assign()</b> — Replace the entire contents</summary>

### Syntax

```cpp
void assign(size_type n, const T& value);
template <class InputIt>
void assign(InputIt first, InputIt last);
void assign(initializer_list<T> list);
```

### Example

```cpp
vector<int> as;
as.assign(3, 8);          // [8, 8, 8]
as.assign({1, 2, 3, 4});  // [1, 2, 3, 4]
```

`assign_range(rg)` does the same from any range **(C++23)**.

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>swap()</b> — Exchange two vectors</summary>

### Syntax

```cpp
void swap(vector& other) noexcept;
// or
std::swap(a, b);
```

### Example

```cpp
vector<int> s1 = {1, 2}, s2 = {3, 4, 5};
s1.swap(s2);       // s1 = [3, 4, 5], s2 = [1, 2]
```

Only the internal pointers are exchanged — no elements are copied.

### Complexity

- Time: `O(1)`

</details>

---

<details>
<summary><b>Comparison Operators</b> — ==, !=, <, <=, >, >=</summary>

### Syntax

```cpp
a == b;   a != b;   a < b;   a <= b;   a > b;   a >= b;
auto r = a <=> b;       // (C++20) three-way comparison
```

### Returns

`bool` (or an ordering for `<=>`). Comparison is **lexicographic**: element by element, and a shorter prefix is smaller.

### Example

```cpp
(vector<int>{1, 2, 3} == vector<int>{1, 2, 3});   // true
(vector<int>{1, 2}    <  vector<int>{1, 3});      // true
(vector<int>{1, 2}    <  vector<int>{1, 2, 0});   // true (shorter prefix)
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>get_allocator()</b> — Access the allocator</summary>

### Syntax

```cpp
allocator_type get_allocator() const noexcept;
```

Returns a copy of the allocator used by the vector. Rarely needed outside custom-allocator code.

</details>

---

# 9. Searching

The following are **algorithms** from `<algorithm>`, not member functions, so they work with iterators.

<details>
<summary><b>std::find()</b> — Linear search</summary>

### Syntax

```cpp
auto it = find(v.begin(), v.end(), value);
```

### Returns

An iterator to the first match, or `v.end()` if not found.

### Example

```cpp
vector<int> al = {5, 2, 8, 2, 9, 1};
auto fi = find(al.begin(), al.end(), 8);
int index = fi - al.begin();                    // 2
bool missing = (find(al.begin(), al.end(), 100) == al.end());   // true
```

### Complexity

- Best: `O(1)`
- Worst: `O(n)`

</details>

---

<details>
<summary><b>std::binary_search()</b> — Check existence in a sorted vector</summary>

### Syntax

```cpp
bool found = binary_search(v.begin(), v.end(), value);
```

### Important

The vector **must be sorted** (in the same order as the comparator).

### Returns

`true` / `false` — it does **not** give the position.

### Complexity

- Time: `O(log n)`

</details>

---

<details>
<summary><b>std::lower_bound() / std::upper_bound()</b> — Find a position in a sorted vector</summary>

### Syntax

```cpp
auto lo = lower_bound(v.begin(), v.end(), value);   // first element >= value
auto hi = upper_bound(v.begin(), v.end(), value);   // first element >  value
```

### Returns

Iterators (possibly `end()`).

### Example

```cpp
vector<int> s = {1, 2, 2, 5, 8, 9};
int lo = lower_bound(s.begin(), s.end(), 2) - s.begin();   // 1
int hi = upper_bound(s.begin(), s.end(), 2) - s.begin();   // 3
int howMany = hi - lo;                                      // 2 copies of 2
```

### Complexity

- Time: `O(log n)`

</details>

---

# 10. Counting & Aggregates

<details>
<summary><b>std::count()</b> — Occurrences of a value</summary>

### Syntax

```cpp
auto n = count(v.begin(), v.end(), value);
auto m = count_if(v.begin(), v.end(), predicate);
```

### Returns

Number of matching elements.

### Example

```cpp
count(al.begin(), al.end(), 2);    // 2
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>std::min_element() / std::max_element()</b> — Smallest and largest</summary>

### Syntax

```cpp
auto mn = min_element(v.begin(), v.end());
auto mx = max_element(v.begin(), v.end());
```

### Returns

An **iterator** to the element (dereference with `*`). Returns `end()` for an empty range — don't dereference it.

### Example

```cpp
*max_element(al.begin(), al.end());   // 9
*min_element(al.begin(), al.end());   // 1
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>std::accumulate()</b> — Sum (or fold) the elements</summary>

### Syntax

```cpp
#include <numeric>
auto total = accumulate(v.begin(), v.end(), initialValue);
```

### Returns

The initial value plus every element. The **type of `initialValue` decides the result type**.

### Example

```cpp
accumulate(al.begin(), al.end(), 0);      // 27 (int)
accumulate(vals.begin(), vals.end(), 0LL);  // use 0LL for large sums (long long)
accumulate(prices.begin(), prices.end(), 0.0);  // use 0.0 for doubles
```

### Complexity

- Time: `O(n)`

</details>

---

# 11. Sorting

<details>
<summary><b>std::sort()</b> — Sort in place</summary>

### Syntax

```cpp
sort(v.begin(), v.end());                       // ascending
sort(v.begin(), v.end(), greater<int>());       // descending
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });   // custom comparator
```

### Returns

Nothing (`void`) — the vector itself is rearranged.

### Example

```cpp
vector<int> al = {5, 2, 8, 2, 9, 1};
sort(al.begin(), al.end());                  // [1, 2, 2, 5, 8, 9]
sort(al.begin(), al.end(), greater<int>());  // [9, 8, 5, 2, 2, 1]
```

`sort` is **not stable**. Use `stable_sort` if equal elements must keep their original order.

### Complexity

- Time: `O(n log n)`
- Space: `O(log n)`

</details>

---

# 12. Rearrangement

<details>
<summary><b>std::reverse()</b> — Reverse the order</summary>

### Syntax

```cpp
reverse(v.begin(), v.end());
```

### Example

```cpp
// [1, 2, 5, 8, 9]  →  [9, 8, 5, 2, 1]
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>std::rotate()</b> — Rotate elements</summary>

### Syntax

```cpp
rotate(v.begin(), v.begin() + k, v.end());     // rotate LEFT by k
rotate(v.rbegin(), v.rbegin() + k, v.rend());  // rotate RIGHT by k
```

### Example

```cpp
vector<int> ro = {1, 2, 3, 4, 5};
rotate(ro.begin(), ro.begin() + 2, ro.end());      // [3, 4, 5, 1, 2]
rotate(ro.rbegin(), ro.rbegin() + 1, ro.rend());   // [2, 3, 4, 5, 1]
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>std::unique()</b> — Remove consecutive duplicates</summary>

### Syntax

```cpp
auto newEnd = unique(v.begin(), v.end());
v.erase(newEnd, v.end());
```

### Important

`unique` only removes **adjacent** duplicates, so **sort first** to remove all duplicates. Like `remove`, it doesn't shrink the vector — you must `erase` the tail.

### Example

```cpp
sort(al.begin(), al.end());                       // [1, 2, 2, 5, 8, 9]
al.erase(unique(al.begin(), al.end()), al.end()); // [1, 2, 5, 8, 9]
```

### Complexity

- Time: `O(n)`

</details>

---

<details>
<summary><b>std::fill() / std::iota()</b> — Bulk assignment</summary>

### Syntax

```cpp
fill(v.begin(), v.end(), value);            // every element = value
iota(v.begin(), v.end(), startValue);       // startValue, +1, +2, ...   (needs <numeric>)
```

### Example

```cpp
vector<int> io(5);
iota(io.begin(), io.end(), 1);     // [1, 2, 3, 4, 5]
fill(io.begin(), io.end(), 0);     // [0, 0, 0, 0, 0]
```

### Complexity

- Time: `O(n)`

</details>

---

# 13. Traversal

<details>
<summary><b>Index Loop</b></summary>

```cpp
for (size_t i = 0; i < v.size(); i++)
    cout << v[i] << " ";
```

Use `size_t` (not `int`) for `i` to avoid signed/unsigned comparison warnings.

</details>

---

<details>
<summary><b>Range-based for Loop</b></summary>

```cpp
for (int x : v)        // copy of each element (cannot modify the vector)
    cout << x << " ";

for (auto& x : v)      // reference (can modify the vector)
    x *= 2;

for (const auto& x : v)   // read-only, no copy (best for strings/large types)
    cout << x << " ";
```

### Example

```cpp
vector<int> it = {1, 2, 3};
for (auto& x : it) x *= 2;      // [2, 4, 6]
```

</details>

---

<details>
<summary><b>Iterator Loop</b></summary>

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";

for (auto it = v.rbegin(); it != v.rend(); ++it)   // backwards
    cout << *it << " ";
```

</details>

---

# 14. 2D Vectors

A 2D vector is simply a **vector of vectors**.

<details>
<summary><b>Creating and Using a Grid</b></summary>

### Syntax

```cpp
vector<vector<int>> grid(rows, vector<int>(cols, initialValue));
```

### Example

```cpp
vector<vector<int>> grid(3, vector<int>(4, 0));   // 3 rows x 4 columns of 0
grid[1][2] = 5;
cout << grid.size();        // 3  (rows)
cout << grid[0].size();     // 4  (columns)
```

Rows can have different lengths (a "jagged" array) because each row is its own vector.

```text
grid:
[0, 0, 0, 0]
[0, 0, 5, 0]
[0, 0, 0, 0]
```

</details>

---

# 15. vector&lt;bool&gt;

<details>
<summary><b>vector&lt;bool&gt;</b> — The special (space-optimized) specialization</summary>

`vector<bool>` stores each element as a **single bit**, so it saves memory but behaves differently from every other `vector<T>`:

- `operator[]` returns a **proxy object**, not a real `bool&`
- `data()` does not exist, and you cannot take the address of an element
- It has an extra member: `flip()`

### Example

```cpp
vector<bool> vb = {true, false, true};
vb.flip();                       // [false, true, false]
bool first = vb[0];              // OK: copy into a real bool
```

If you need real references or raw access, use `vector<char>`, `vector<int>`, or `std::bitset` / `std::deque<bool>` instead.

</details>

---

# 16. Iterator Invalidation

After certain operations, existing iterators, pointers, and references to elements may become **invalid** — using them is undefined behavior.

| Operation | What gets invalidated |
|---|---|
| `push_back`, `emplace_back` | **All** if a reallocation happens; otherwise only `end()` |
| `insert`, `emplace` | **All** if a reallocation happens; otherwise everything at/after the insertion point |
| `pop_back` | The last element and `end()` |
| `erase` | Everything at/after the erased element |
| `clear` | **All** |
| `reserve`, `shrink_to_fit` | **All** if they reallocate |
| `resize` | Same rules as insert / erase |
| `assign`, `operator=` | **All** |
| `swap` | None (iterators now refer to the *other* vector) |

### Safe pattern when erasing in a loop

```cpp
for (auto it = v.begin(); it != v.end(); )
{
    if (*it % 2 == 0)
        it = v.erase(it);     // erase returns the next valid iterator
    else
        ++it;
}
```

---

# 17. Common Pitfalls

- **`vector<int> v(5, 1)` vs `vector<int> v{5, 1}`** — parentheses mean "5 copies of 1" (`[1,1,1,1,1]`); braces mean "the two values 5 and 1" (`[5, 1]`).
- **`v.size() - 1` on an empty vector** — `size()` is unsigned, so `0 - 1` wraps to `18446744073709551615`. Check `empty()` first, or cast to `int`.
- **`operator[]` never checks bounds** — use `at()` while debugging.
- **`front()`, `back()`, `pop_back()` on an empty vector** are undefined behavior.
- **`remove` / `unique` don't shrink** the vector — always pair them with `erase`.
- **Keeping an iterator or reference across `push_back`** — it can dangle after a reallocation.
- **Modifying the vector while a range-for loop is running** is undefined behavior.
- **`resize` vs `reserve`** — `resize` changes how many elements exist; `reserve` only prepares memory.
- **Passing a vector by value copies it** — pass `const vector<int>&` instead.
- **`for (auto x : v)` copies each element** — use `const auto&` for strings and other large types.
- **`vector<bool>` is not a normal vector** (see section 15).

---

# 18. Complete Function Checklist

| # | Function | Category |
|---|---|---|
| 1 | `vector()` | Constructor |
| 2 | `vector(n)` | Constructor |
| 3 | `vector(n, value)` | Constructor |
| 4 | `vector(first, last)` | Constructor |
| 5 | `vector(initializer_list)` | Constructor |
| 6 | `vector(const vector&)` | Constructor |
| 7 | `vector(vector&&)` | Constructor |
| 8 | `operator=` | Assignment |
| 9 | `~vector()` | Destructor |
| 10 | `operator[]` | Element Access |
| 11 | `at()` | Element Access |
| 12 | `front()` | Element Access |
| 13 | `back()` | Element Access |
| 14 | `data()` | Element Access |
| 15 | `begin()` / `end()` | Iterators |
| 16 | `cbegin()` / `cend()` | Iterators |
| 17 | `rbegin()` / `rend()` | Iterators |
| 18 | `crbegin()` / `crend()` | Iterators |
| 19 | `size()` | Capacity |
| 20 | `empty()` | Capacity |
| 21 | `capacity()` | Capacity |
| 22 | `max_size()` | Capacity |
| 23 | `reserve()` | Capacity |
| 24 | `shrink_to_fit()` | Capacity |
| 25 | `resize()` | Capacity |
| 26 | `push_back()` | Insertion |
| 27 | `emplace_back()` | Insertion |
| 28 | `insert()` | Insertion |
| 29 | `emplace()` | Insertion |
| 30 | `append_range()` / `insert_range()` | Insertion (C++23) |
| 31 | `pop_back()` | Deletion |
| 32 | `erase()` | Deletion |
| 33 | `clear()` | Deletion |
| 34 | `std::erase()` / `std::erase_if()` | Deletion (C++20) |
| 35 | `assign()` / `assign_range()` | Assign |
| 36 | `swap()` | Swap |
| 37 | `==`, `!=`, `<`, `<=`, `>`, `>=`, `<=>` | Comparison |
| 38 | `get_allocator()` | Allocator |
| 39 | `std::find()` | Searching |
| 40 | `std::binary_search()` | Searching |
| 41 | `std::lower_bound()` / `std::upper_bound()` | Searching |
| 42 | `std::count()` / `std::count_if()` | Counting |
| 43 | `std::min_element()` / `std::max_element()` | Aggregates |
| 44 | `std::accumulate()` | Aggregates |
| 45 | `std::sort()` | Sorting |
| 46 | `std::reverse()` | Rearrangement |
| 47 | `std::rotate()` | Rearrangement |
| 48 | `std::unique()` | Rearrangement |
| 49 | `std::remove()` / `std::remove_if()` | Rearrangement |
| 50 | `std::fill()` / `std::iota()` | Rearrangement |

---

# 19. Complexity Cheat Sheet

| Operation | Time |
|---|---:|
| `operator[]`, `at()`, `front()`, `back()`, `data()` | `O(1)` |
| `size()`, `empty()`, `capacity()` | `O(1)` |
| `push_back()` / `emplace_back()` | `O(1)` amortized |
| `pop_back()` | `O(1)` |
| `insert()` / `emplace()` at end | `O(1)` amortized |
| `insert()` / `emplace()` at start or middle | `O(n)` |
| `erase()` at end | `O(1)` |
| `erase()` at start or middle | `O(n)` |
| `clear()` | `O(n)` |
| `resize()` | `O(n)` |
| `reserve()` / `shrink_to_fit()` | `O(n)` when reallocating |
| `assign()` | `O(n)` |
| `swap()` | `O(1)` |
| Copy constructor / copy assignment | `O(n)` |
| Move constructor / move assignment | `O(1)` |
| Comparison operators | `O(n)` |
| `find()` / `count()` | `O(n)` |
| `binary_search()` / `lower_bound()` / `upper_bound()` | `O(log n)` |
| `min_element()` / `max_element()` / `accumulate()` | `O(n)` |
| `sort()` | `O(n log n)` |
| `reverse()` / `rotate()` / `unique()` / `remove()` | `O(n)` |
| `fill()` / `iota()` | `O(n)` |

---

# 20. Important Concepts

- `size()` is **how many elements exist**; `capacity()` is **how many fit before reallocating**.
- A vector's memory is **contiguous**, so `&v[0]` / `data()` can be passed to C functions and iteration is cache-friendly.
- `push_back` is amortized `O(1)` because capacity grows geometrically, not by one slot at a time.
- Inserting or erasing anywhere except the end shifts elements, so it costs `O(n)`.
- `clear()` and `resize()` to a smaller size **do not** give memory back; only `shrink_to_fit()` may.
- `reserve()` before a loop of `push_back` calls avoids repeated reallocations.
- `operator[]` is fast but unchecked; `at()` is checked and throws `std::out_of_range`.
- `sort`, `find`, `reverse`, `unique`, etc. are **not** members — they are `<algorithm>` functions that take iterators.
- `binary_search`, `lower_bound`, and `upper_bound` require a **sorted** vector.
- `remove` and `unique` only rearrange; they need `erase` (or C++20 `std::erase`) to actually shrink the vector.
- Copying a vector copies **every element** (deep copy); moving only transfers the pointer.
- Elements must be accessed through valid iterators — see the invalidation table in section 16.
- The vector frees its own memory automatically (RAII); there is never a manual `delete[]`.

---

# 21. Function Categories

### Construction & Assignment
- Constructors
- `operator=`
- `assign()`
- Destructor

### Element Access
- `operator[]`
- `at()`
- `front()` / `back()`
- `data()`

### Iterators
- `begin()` / `end()`
- `cbegin()` / `cend()`
- `rbegin()` / `rend()`

### Capacity
- `size()` / `empty()`
- `capacity()` / `max_size()`
- `reserve()` / `shrink_to_fit()`
- `resize()`

### Modification
- Insertion: `push_back()`, `emplace_back()`, `insert()`, `emplace()`
- Deletion: `pop_back()`, `erase()`, `clear()`, `std::erase()`
- `swap()`

### Searching
- `find()`
- `binary_search()`
- `lower_bound()` / `upper_bound()`

### Counting & Aggregates
- `count()`
- `min_element()` / `max_element()`
- `accumulate()`

### Sorting & Rearrangement
- `sort()`
- `reverse()`
- `rotate()`
- `unique()`
- `remove()`
- `fill()` / `iota()`

### Comparison
- `==`, `!=`, `<`, `<=`, `>`, `>=`, `<=>`

## 📌 Key Takeaway

`std::vector` is a ready-made dynamic array that handles resizing, memory cleanup, and bounds-aware access for you — the same ideas as a hand-written array (`size`, `capacity`, `regrow`, `shiftLeft`, `shiftRight`), but wrapped in a safe, standard interface. Pair its member functions with the `<algorithm>` and `<numeric>` functions (`sort`, `find`, `unique`, `rotate`, `accumulate`, ...) and you cover almost every array task you will meet in DSA.
