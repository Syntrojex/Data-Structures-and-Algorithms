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
