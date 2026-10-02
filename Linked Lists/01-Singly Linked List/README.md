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
<summary><b>operator++()</b> — Advance</summary>

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
