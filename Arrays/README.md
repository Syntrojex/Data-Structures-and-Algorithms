# Dynamic Array

A complete **Dynamic Array implementation in C++** covering resizing, insertion, deletion, update, searching, duplicate removal, reversal, rotation, and multiple sorting algorithms — implemented from scratch using raw pointers.

## 📌 Overview

A Dynamic Array is a linear data structure that stores elements in **contiguous memory** and automatically grows when it runs out of space. Unlike a fixed-size array, it exposes `size` (how many elements are actually stored) separately from `capacity` (how much memory is currently allocated) — and doubles its capacity via `regrow()` whenever it fills up.

```text
capacity = 4
size     = 3

Index:    0     1     2     3
Array: [ 10  |  20  |  30  |  _  ]
                              ↑
                        empty slot (capacity - size)
```

```text
size == capacity  →  regrow() doubles capacity, copies old elements, frees old block
```

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

<details>
<summary><b>updateAtIndex(int index, int value)</b></summary>

```cpp
void updateAtIndex(int index, int value)
{
    if (index < 0 || index >= size)
    {
        cout << "Invalid Index!" << endl;
        return;
    }

    arr[index] = value;
}
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>updateAtEnd(int value)</b></summary>

```cpp
void updateAtEnd(int value)
{
    if (size == 0)
    {
        cout << "Array is Empty!" << endl;
        return;
    }

    arr[size - 1] = value;
}
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

</details>

---

# 7. Searching

<details>
<summary><b>linearSearch(int value)</b> — Search in any array</summary>

### Purpose

Checks every element one by one until the required value is found.

Works on both **sorted and unsorted arrays**.

### Code

```cpp
int linearSearch(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }

    return -1;
}
```

### Return Value

- Returns index if found
- Returns `-1` if not found

### Complexity

- Best: `O(1)`
- Worst: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>binarySearch(int value)</b> — Search in a sorted array</summary>

### Important

**Binary Search requires the array to be sorted.**

### Code

```cpp
int binarySearch(int value)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] < value)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}
```

### Complexity

- Best: `O(1)`
- Worst: `O(log n)`
- Space: `O(1)`

</details>

---

# 8. Duplicate Removal

<details>
<summary><b>removeDuplicates()</b> — Remove duplicate values</summary>

### Purpose

Removes duplicate values from an **unsorted array** while keeping the first occurrence.

### Example

```text
Before:
[10, 20, 10, 30, 20]

After:
[10, 20, 30]
```

### Code

```cpp
void removeDuplicates()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size;)
        {
            if (arr[i] == arr[j])
            {
                shiftLeft(j);
                size--;
            }
            else
            {
                j++;
            }
        }
    }
}
```

### Complexity

- Time: `O(n²)`
- Space: `O(1)`

### Note

This version does not require the array to be sorted.

</details>

---

# 9. Reverse

<details>
<summary><b>reverse(int start, int end)</b> — Reverse a range</summary>

```cpp
void reverse(int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 10. Rotation

<details>
<summary><b>rotateRight(int k)</b> — Rotate array to the right</summary>

### Code

```cpp
void rotateRight(int k)
{
    if (size <= 1)
    {
        return;
    }

    k = k % size;

    reverse(0, size - 1);
    reverse(0, k - 1);
    reverse(k, size - 1);
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>rotateLeft(int k)</b> — Rotate array to the left</summary>

### Code

```cpp
void rotateLeft(int k)
{
    if (size <= 1)
    {
        return;
    }

    k = k % size;

    reverse(0, k - 1);
    reverse(k, size - 1);
    reverse(0, size - 1);
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 11. Sorting Algorithms

## Bubble Sort

<details>
<summary><b>bubbleSort()</b> — Repeatedly swap adjacent elements</summary>

### Idea

Larger elements gradually move toward the end of the array.

### Code

```cpp
void bubbleSort()
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}
```

### Complexity

- Best: `O(n)` with optimization
- Average: `O(n²)`
- Worst: `O(n²)`
- Space: `O(1)`

</details>

---

## Selection Sort

<details>
<summary><b>selectionSort()</b> — Find minimum and place it correctly</summary>

### Idea

Find the smallest element in the unsorted portion and put it at the current position.

### Code

```cpp
void selectionSort()
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
```

### Complexity

- Best: `O(n²)`
- Average: `O(n²)`
- Worst: `O(n²)`
- Space: `O(1)`

</details>

---

## Insertion Sort

<details>
<summary><b>insertionSort()</b> — Insert each element into its correct position</summary>

### Idea

Maintains a sorted portion on the left and inserts each new element into its correct position.

### Code

```cpp
void insertionSort()
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
```

### Complexity

- Best: `O(n)`
- Average: `O(n²)`
- Worst: `O(n²)`
- Space: `O(1)`

</details>

---

## Merge Sort

<details>
<summary><b>mergeSort()</b> — Divide and merge sorted halves</summary>

### Helper: merge

```cpp
void merge(int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int* left = new int[leftSize];
    int* right = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        left[i] = arr[start + i];
    }

    for (int i = 0; i < rightSize; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < leftSize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}
```

### Recursive Helper

```cpp
void mergeSortHelper(int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSortHelper(start, mid);
    mergeSortHelper(mid + 1, end);

    merge(start, mid, end);
}
```

### Public Function

```cpp
void mergeSort()
{
    if (size > 1)
    {
        mergeSortHelper(0, size - 1);
    }
}
```

### Complexity

- Best: `O(n log n)`
- Average: `O(n log n)`
- Worst: `O(n log n)`
- Space: `O(n)`

</details>

---

## Quick Sort

<details>
<summary><b>quickSort()</b> — Partition around a pivot</summary>

### Helper: partition

```cpp
int partition(int start, int end)
{
    int pivot = arr[end];

    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    return i + 1;
}
```

### Recursive Helper

```cpp
void quickSortHelper(int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivotIndex = partition(start, end);

    quickSortHelper(start, pivotIndex - 1);
    quickSortHelper(pivotIndex + 1, end);
}
```

### Public Function

```cpp
void quickSort()
{
    if (size > 1)
    {
        quickSortHelper(0, size - 1);
    }
}
```

### Complexity

- Best: `O(n log n)`
- Average: `O(n log n)`
- Worst: `O(n²)`
- Space: `O(log n)` average recursion stack
- Worst recursion space: `O(n)`

</details>

---

# 12. Display

<details>
<summary><b>display()</b> — Display current elements</summary>

```cpp
void display()
{
    if (size > 0)
    {
        cout << "\nArray is: [";

        for (int i = 0; i < size; i++)
        {
            cout << arr[i];

            if (i != size - 1)
            {
                cout << ",";
            }
        }

        cout << "]" << endl;
    }
    else
    {
        cout << "Array is Empty!!" << endl;
    }
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 13. Destructor

<details>
<summary><b>~Array()</b> — Release dynamic memory</summary>

```cpp
~Array()
{
    delete[] arr;
    arr = nullptr;
}
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

</details>

---

# 14. Complete Function Checklist

| # | Function | Category |
|---|---|---|
| 1 | `isFull()` | Helper |
| 2 | `regrow()` | Dynamic Memory |
| 3 | `shiftRight()` | Helper |
| 4 | `shiftLeft()` | Helper |
| 5 | `Array()` | Constructor |
| 6 | `Array(int)` | Constructor |
| 7 | `insertAtStart()` | Insertion |
| 8 | `insertAtIndex()` | Insertion |
| 9 | `insertAtEnd()` | Insertion |
| 10 | `deleteFromStart()` | Deletion |
| 11 | `deleteFromIndex()` | Deletion |
| 12 | `deleteFromEnd()` | Deletion |
| 13 | `updateAtStart()` | Update |
| 14 | `updateAtIndex()` | Update |
| 15 | `updateAtEnd()` | Update |
| 16 | `linearSearch()` | Searching |
| 17 | `binarySearch()` | Searching |
| 18 | `removeDuplicates()` | Duplicate Removal |
| 19 | `reverse()` | Reversal |
| 20 | `rotateRight()` | Rotation |
| 21 | `rotateLeft()` | Rotation |
| 22 | `bubbleSort()` | Sorting |
| 23 | `selectionSort()` | Sorting |
| 24 | `insertionSort()` | Sorting |
| 25 | `merge()` | Merge Sort Helper |
| 26 | `mergeSortHelper()` | Merge Sort Helper |
| 27 | `mergeSort()` | Sorting |
| 28 | `partition()` | Quick Sort Helper |
| 29 | `quickSortHelper()` | Quick Sort Helper |
| 30 | `quickSort()` | Sorting |
| 31 | `display()` | Utility |
| 32 | `~Array()` | Destructor |

---

# 15. Complexity Cheat Sheet

| Operation / Algorithm | Time |
|---|---:|
| Access by index | `O(1)` |
| Update by index | `O(1)` |
| Insert at end | `O(1)` average |
| Insert at start | `O(n)` |
| Insert at index | `O(n)` |
| Delete from end | `O(1)` |
| Delete from start | `O(n)` |
| Delete from index | `O(n)` |
| Linear Search | `O(n)` |
| Binary Search | `O(log n)` |
| Reverse | `O(n)` |
| Rotate Left | `O(n)` |
| Rotate Right | `O(n)` |
| Remove Duplicates | `O(n²)` |
| Bubble Sort | `O(n²)` |
| Selection Sort | `O(n²)` |
| Insertion Sort | `O(n²)` |
| Merge Sort | `O(n log n)` |
| Quick Sort | `O(n log n)` average |
| Display | `O(n)` |

---

# 16. Important Concepts

- `size` tells you **how many elements currently exist**.
- `capacity` tells you **how much memory is currently allocated**.
- Insertion increases `size`.
- Deletion decreases `size`.
- `regrow()` increases `capacity`.
- `shiftRight()` is used mainly for insertion.
- `shiftLeft()` is used mainly for deletion.
- Binary Search only works correctly on a **sorted array**.
- `reverse()` is also used as a helper for array rotation.
- Sorting algorithms modify the array **in-place**, except Merge Sort which uses extra arrays.
- Duplicate removal shown above works without requiring the array to be sorted.

---

# 17. Algorithm Categories

### Basic Dynamic Array
- Constructors
- `isFull()`
- `regrow()`
- Shifting
- Destructor

### Modification
- Insertion
- Deletion
- Update

### Searching
- Linear Search
- Binary Search

### Rearrangement
- Reverse
- Rotate Left
- Rotate Right
- Remove Duplicates

### Sorting
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
