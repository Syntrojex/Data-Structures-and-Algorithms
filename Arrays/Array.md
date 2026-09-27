# Dynamic Array — Complete C++ DSA Function Reference

> A practical, copy-ready reference for a custom Dynamic Array in C++.
>
> Includes **Insertion, Deletion, Update, Searching, Duplicate Removal, Reverse, Rotation, and Sorting Algorithms**.

---

# 1. Class Structure

```cpp
class Array
{
private:
    int* arr;
    int size;
    int capacity;
};
```

- `arr` → dynamically allocated array
- `size` → number of currently stored elements
- `capacity` → total allocated space

---

# 2. Helper Functions

<details>
<summary><b>isFull()</b> — Check whether the array is full</summary>

### Purpose

Checks whether the current number of elements has reached the allocated capacity.

### Code

```cpp
bool isFull()
{
    if (size == capacity)
    {
        return true;
    }

    return false;
}
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>regrow()</b> — Double the array capacity</summary>

### Purpose

Creates a larger array, copies the existing elements, deletes the old array, and updates the capacity.

### Code

```cpp
void regrow()
{
    int* newArr = new int[capacity * 2];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;

    arr = newArr;
    capacity = capacity * 2;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(n)`

</details>

---

<details>
<summary><b>shiftRight(int fromIndex)</b> — Shift elements right</summary>

### Purpose

Moves elements one position to the right to create an empty position for insertion.

### Code

```cpp
void shiftRight(int fromIndex)
{
    for (int i = size - 1; i >= fromIndex; i--)
    {
        arr[i + 1] = arr[i];
    }
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>shiftLeft(int fromIndex)</b> — Shift elements left</summary>

### Purpose

Moves elements one position to the left after deletion.

### Code

```cpp
void shiftLeft(int fromIndex)
{
    for (int i = fromIndex; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 3. Constructors

<details>
<summary><b>Default Constructor</b></summary>

```cpp
Array()
{
    capacity = 2;
    arr = new int[capacity];
    size = 0;
}
```

</details>

---

<details>
<summary><b>Parameterized Constructor</b></summary>

```cpp
Array(int capacity)
{
    this->capacity = capacity;
    arr = new int[capacity];
    size = 0;
}
```

</details>

---

# 4. Insertion

<details>
<summary><b>insertAtStart(int value)</b> — Insert at beginning</summary>

```cpp
void insertAtStart(int value)
{
    if (isFull())
    {
        regrow();
    }

    if (size > 0)
    {
        shiftRight(0);
    }

    arr[0] = value;
    size++;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)` excluding regrow

</details>

---

<details>
<summary><b>insertAtIndex(int value, int index)</b> — Insert at a specific index</summary>

```cpp
void insertAtIndex(int value, int index)
{
    if (index < 0 || index > size)
    {
        cout << "Invalid Index!" << endl;
        return;
    }

    if (isFull())
    {
        regrow();
    }

    if (index < size)
    {
        shiftRight(index);
    }

    arr[index] = value;
    size++;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)` excluding regrow

</details>

---

<details>
<summary><b>insertAtEnd(int value)</b> — Insert at end</summary>

```cpp
void insertAtEnd(int value)
{
    if (isFull())
    {
        regrow();
    }

    arr[size] = value;
    size++;
}
```

### Complexity

- Average: `O(1)`
- Worst case: `O(n)` when regrow occurs

</details>

---

# 5. Deletion

<details>
<summary><b>deleteFromStart()</b> — Delete first element</summary>

```cpp
void deleteFromStart()
{
    if (size == 0)
    {
        cout << "Array is Empty!" << endl;
        return;
    }

    shiftLeft(0);
    size--;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>deleteFromIndex(int index)</b> — Delete from a specific index</summary>

```cpp
void deleteFromIndex(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Invalid Index!" << endl;
        return;
    }

    shiftLeft(index);
    size--;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>deleteFromEnd()</b> — Delete last element</summary>

```cpp
void deleteFromEnd()
{
    if (size == 0)
    {
        cout << "Array is Empty!" << endl;
        return;
    }

    size--;
}
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

</details>

---

# 6. Update

<details>
<summary><b>updateAtStart(int value)</b></summary>

```cpp
void updateAtStart(int value)
{
    if (size == 0)
    {
        cout << "Array is Empty!" << endl;
        return;
    }

    arr[0] = value;
}
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

</details>

---
