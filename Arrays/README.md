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
