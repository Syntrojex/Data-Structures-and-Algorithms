<h1 align="center">Singly Linked List</h1>

A complete **Singly Linked List implementation in C++** covering fundamental operations, custom iterator traversal, function-pointer traversal, and practical linked-list algorithms.

## 📌 Overview

A Singly Linked List is a linear data structure made up of nodes. Each node stores a value and a pointer to the next node.

```text
Head
 ↓
[10 | •] → [20 | •] → [30 | •] → NULL
```

Unlike arrays, linked-list nodes do not need contiguous memory locations.

---

# 1. Node Structure

```cpp
class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
```

- `data` → value stored in the node
- `next` → pointer to the following node (`NULL` for the last node)

The list itself only keeps two private members:

```cpp
Node* head;
int size;
```

- `head` → pointer to the first node (`NULL` when the list is empty)
- `size` → number of nodes currently in the list

---

# 2. Custom Iterator

<details>
<summary><b>Iterator Constructor</b></summary>

Stores the node from which traversal begins.

```cpp
Iterator(Node* node)
{
    current = node;
}
```

</details>

---

<details>
<summary><b>operator*()</b> — Dereference</summary>

Returns the current node's data.

```cpp
int& operator*()
{
    return current->data;
}
```

This allows:

```cpp
cout << *it;
```

</details>

---

<details>
<summary><b>operator++()</b> — Increments Iterator</summary>

Moves the iterator to the next node.

```cpp
Iterator& operator++()
{
    if (current != NULL)
    {
        current = current->next;
    }
    return *this;
}
```

```text
[10] → [20] → [30] → NULL
 ↑
it

++it

[10] → [20] → [30] → NULL
         ↑
         it
```

</details>

---

<details>
<summary><b>operator!=(), begin(), end()</b> — Comparison and range endpoints</summary>
<br>
 
```cpp
bool operator!=(const Iterator& other)
{
    if (current != other.current)
    {
        return true;
    }
    return false;
}

Iterator begin()
{
    return Iterator(head);
}

Iterator end()
{
    return Iterator(NULL);
}
```

Together they support:

```cpp
for (auto it = l1.begin(); it != l1.end(); ++it)
    cout << *it;
```

</details>

---

# 3. Helper Functions

<details>
<summary><b>copyFrom(const SinglyLinkedList& other)</b> — Deep-copy every node </summary>

### Purpose

Walks `other`'s nodes and re-inserts each value into `this` (already-empty) list. Used by the copy constructor and the copy assignment operator.

### Code

```cpp
void copyFrom(const SinglyLinkedList& other)
{
    Node* otherTemp = other.head;
    while (otherTemp != NULL)
    {
        insertAtEnd(otherTemp->data);
        otherTemp = otherTemp->next;
    }
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary, excluding the copied nodes

</details>

---

<details>
<summary><b>clear()</b> — Free every node </summary>

### Purpose

Deletes every node and resets the list to empty. Used by the destructor and the copy assignment operator.

### Code

```cpp
void clear()
{
    Node* current = head;
    while (current != NULL)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = NULL;
    size = 0;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 4. Constructors

<details>
<summary><b>Default Constructor</b></summary>

```cpp
SinglyLinkedList()
{
    head = NULL;
    size = 0;
}
```

</details>

---

<details>
<summary><b>Copy Constructor</b></summary>

### Purpose

The class manages raw pointers and already defines a destructor, so without this the compiler-generated shallow copy would let two lists share (and later double-delete) the same nodes — this is the "Rule of Three."

### Code

```cpp
SinglyLinkedList(const SinglyLinkedList& other)
{
    head = NULL;
    size = 0;
    copyFrom(other);
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary

</details>

---

<details>
<summary><b>Copy Assignment Operator</b> </summary>

### Purpose

Same Rule-of-Three reason as the copy constructor. Guards against self-assignment (`l1 = l1;`) before clearing and re-copying.

### Code

```cpp
SinglyLinkedList& operator=(const SinglyLinkedList& other)
{
    if (this != &other)
    {
        clear();
        copyFrom(other);
    }
    return *this;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)` auxiliary

</details>

---

# 5. Basic Operations

<details>
<summary><b>isEmpty()</b> — Check whether the list has no nodes</summary>

```cpp
bool isEmpty()
{
    if (head == NULL)
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
<summary><b>getSize()</b> — Return the element count <i>(added)</i></summary>

`size` was already tracked internally but had no public getter.

```cpp
int getSize() const
{
    return size;
}
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>display()</b> — Print every node</summary>

```cpp
void display()
{
    if (isEmpty())
    {
        cout << "LinkedList is Empty" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
```

### Example

```text
10 → 20 → 30 → NULL
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 6. Insertion

<details>
<summary><b>insertAtStart(int value)</b> — Insert at beginning</summary>

```cpp
void insertAtStart(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}
```

### Dry Run

```text
Before: 10 → 20 → NULL
Insert 5
After:  5 → 10 → 20 → NULL
```

### Complexity

- Time: `O(1)`
- Space: `O(1)` excluding the new node

</details>

---

<details>
<summary><b>insertAtEnd(int value)</b> — Insert at end</summary>

```cpp
void insertAtEnd(int value)
{
    if (isEmpty())
    {
        insertAtStart(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    size++;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)` excluding the new node

</details>

---

<details>
<summary><b>insertAt(int position, int value)</b> — Insert at a 1-based position</summary>

```cpp
void insertAt(int position, int value)
{
    if (position < 1 || position > size + 1)
    {
        cout << "Invalid Position! Position must be between 1 and " << size + 1 << endl;
        return;
    }

    if (position == 1)
    {
        insertAtStart(value);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;

    size++;
}
```

### Example

```text
Before:
10 → 20 → 30

insertAt(2, 15)

After:
10 → 15 → 20 → 30
```

### Complexity

- Time: `O(n)`
- Space: `O(1)` excluding the new node

</details>

---

# 7. Deletion

<details>
<summary><b>deleteFromStart()</b> — Delete first node</summary>

```cpp
void deleteFromStart()
{
    if (isEmpty())
    {
        cout << "LinkedList is Empty" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}
```

### Complexity

- Time: `O(1)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>deleteFromEnd()</b> — Delete last node <i>(renamed from deleteFormEnd)</i></summary>

```cpp
void deleteFromEnd()
{
    if (isEmpty())
    {
        cout << "List is Empty" << endl;
        return;
    }

    if (head->next == NULL)
    {
        deleteFromStart();
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node* temp2 = temp->next;
    temp->next = NULL;
    delete temp2;
    size--;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>deleteAt(int position)</b> — Delete at a 1-based position</summary>

```cpp
void deleteAt(int position)
{
    if (position < 1 || position > size)
    {
        cout << "Out of Bounds" << endl;
        return;
    }

    if (position == 1)
    {
        deleteFromStart();
        return;
    }

    if (position == size)
    {
        deleteFromEnd();
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }

    Node* temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
    size--;
}
```

### Example

```text
Before:
10 → 20 → 30 → 40

deleteAt(3)

After:
10 → 20 → 40
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>emptyAfter(int position)</b> — Delete every node after a position</summary>

```cpp
void emptyAfter(int position)
{
    if (position < 1 || position >= size)
    {
        if (position == size)
        {
            return;
        }
        cout << "Out of Bounds" << endl;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }

    Node* current = temp->next;
    temp->next = NULL;

    while (current != NULL)
    {
        Node* temp2 = current->next;
        delete current;
        current = temp2;
        size--;
    }
}
```

### Example

```text
Before:
10 → 20 → 30 → 40 → 50

emptyAfter(3)

After:
10 → 20 → 30 → NULL
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 8. Update

<details>
<summary><b>updateAtStart(int value)</b></summary>

```cpp
void updateAtStart(int value)
{
    if (isEmpty())
    {
        cout << "List is Empty" << endl;
        return;
    }

    head->data = value;
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
    if (isEmpty())
    {
        cout << "List is Empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->data = value;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>updateAt(int position, int value)</b></summary>

```cpp
void updateAt(int position, int value)
{
    if (position < 1 || position > size)
    {
        cout << "Out of Bounds!" << endl;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    temp->data = value;
}
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 9. Searching

<details>
<summary><b>search(int value)</b> — Print whether a value exists</summary>

```cpp
void search(int value)
{
    if (isEmpty())
    {
        cout << "List is Empty. Element can't be found" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Element Found in List" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Element Not Found" << endl;
}
```

### Complexity

- Best: `O(1)`
- Worst: `O(n)`
- Space: `O(1)`

</details>

---

<details>
<summary><b>indexOf(int value)</b> — Return the 1-based position <i>(added)</i></summary>

Same linear walk as `search()`, but returns the position instead of only printing — useful when the caller needs the location, not just a yes/no.

```cpp
int indexOf(int value)
{
    Node* temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }

    return -1;
}
```

### Return Value

- Returns 1-based position if found
- Returns `-1` if not found

### Complexity

- Best: `O(1)`
- Worst: `O(n)`
- Space: `O(1)`

</details>

---

# 10. Reverse

<details>
<summary><b>reverse()</b> — Reverse the list in place</summary>

```cpp
void reverse()
{
    Node* prev = NULL;
    Node* current = head;
    Node* next2 = NULL;

    while (current != NULL)
    {
        next2 = current->next;
        current->next = prev;
        prev = current;
        current = next2;
    }
    head = prev;
}
```

### Example

```text
Before:
10 → 20 → 30 → NULL

After:
30 → 20 → 10 → NULL
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 11. Rotation

<details>
<summary><b>rotate(int k)</b> — Rotate the list to the right</summary>

```cpp
void rotate(int k)
{
    if (isEmpty() || head->next == NULL || k == 0)
    {
        return;
    }

    k = k % size;
    if (k == 0)
    {
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;

    int stepsToNewTail = size - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++)
    {
        newTail = newTail->next;
    }

    head = newTail->next;
    newTail->next = NULL;
}
```

### Example

```text
Original:
1 → 2 → 3 → 4 → 5

rotate(2)

Result:
4 → 5 → 1 → 2 → 3
```

### Note

The last node is temporarily connected to `head`, a new tail is located, and the temporary circular link is broken. `k %= size` prevents unnecessary full rotations.

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---

# 12. Find Middle

<details>
<summary><b>findMiddle()</b> — Slow/fast pointer technique</summary>

```cpp
int findMiddle()
{
    if (isEmpty())
    {
        cout << "List is Empty" << endl;
        return -1;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}
```

### Idea

`slow` moves one node at a time, `fast` moves two. When `fast` reaches the end, `slow` is at the middle. For an even-sized list, this returns the **second middle**.

```text
10 → 20 → 30 → 40
          ↑
        result (30)
```

### Complexity

- Time: `O(n)`
- Space: `O(1)`

</details>

---
