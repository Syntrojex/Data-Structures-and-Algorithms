
# `std::stack`

A practical reference for the C++ `std::stack`, a container adapter that follows the LIFO (Last In, First Out) principle. The last element inserted is the first one removed. Covers commonly used operations in competitive programming.

## 1. Header & Declaration

<details>
<summary><b>Declaration</b></summary>
<br>

```cpp
#include <stack>
using namespace std;

stack<int> st;
```

</details>

## 2. Accessing Elements

<details>
<summary><b>top()</b></summary>
<br>

```cpp
st.top();  // Returns the top element of the stack
```

**Important:** `top()` accesses the most recently inserted element. It does not remove it.

</details>

## 3. Adding Elements

<details>
<summary><b>push(), emplace()</b></summary>
<br>

```cpp
st.push(10);     // Adds 10 to the top
st.push(20);     // Adds 20 to the top

st.emplace(30);  // Constructs and adds 30 to the top
```

</details>

## 4. Removing Elements

<details>
<summary><b>pop()</b></summary>
<br>

```cpp
st.pop();  // Removes the top element
```

**Important:**
- `pop()` removes the top element.
- It does not return the removed element.
- Use `top()` before `pop()` if you need its value.

</details>

## 5. Size & Empty Check

<details>
<summary><b>size(), empty()</b></summary>
<br>

```cpp
st.size();   // Returns the number of elements
st.empty();  // Returns true if stack is empty
```

</details>

## 6. Processing Elements

<details>
<summary><b>Using top() and pop()</b></summary>
<br>

```cpp
while (!st.empty())
{
    cout << st.top() << " ";
    st.pop();
}
```

**Important:** This processes elements from top to bottom and empties the stack.

</details>

## 7. Common Mistakes & Important Notes

- Stack follows LIFO.
- `top()` accesses the latest inserted element.
- `pop()` removes the top element but does not return it.
- You cannot access elements using indexes.
- Stack does not support normal iterators or direct traversal.
- Always check `empty()` before accessing `top()` or calling `pop()`.

## 8. Complexity Cheat Sheet

| Operation | Time Complexity |
|---|---|
| `top()` | O(1) |
| `push()` | O(1) |
| `emplace()` | O(1) |
| `pop()` | O(1) |
| `size()` | O(1) |
| `empty()` | O(1) |

## 9. Key Takeaway

`std::stack` is useful for LIFO problems such as balanced parentheses, expression evaluation, and next greater element.

