# Introduction to Advanced Data Structures and Algorithms (ADSA)

Welcome to your journey into Advanced Data Structures and Algorithms! This guide will lay the foundation by explaining what data structures are, how to classify them, and how to start building your own using C++.

## 1. What is a Data Structure?

A **Data Structure** is a specialized format for organizing, processing, retrieving, and storing data. It is not just about storing data; it's about storing it in a way that makes operations (like access, search, insertion, and deletion) efficient.

Think of it like organizing a library:
- You could pile books randomly (inefficient to find a specific one).
- You could sort them by genre and author (efficient to find).

### Classification of Data Structures

Data structures are generally classified into two main categories:

#### A. Primitive vs. Non-Primitive
1.  **Primitive Data Structures**: These are basic structures directly operated upon by machine instructions.
    *   Examples: `int`, `float`, `char`, `bool`, `double`.
2.  **Non-Primitive Data Structures**: These are derived from primitive data structures and are used to store groups of data.
    *   Examples: Arrays, Linked Lists, Stacks, Trees.

#### B. Linear vs. Non-Linear (Non-Primitive)
1.  **Linear Data Structures**: Data elements are arranged sequentially or linearly. Each element is attached to its previous and next adjacent elements.
    *   **Arrays**: Fixed-size, contiguous memory.
    *   **Linked Lists**: Dynamic size, non-contiguous memory.
    *   **Stacks**: LIFO (Last In, First Out).
    *   **Queues**: FIFO (First In, First Out).
2.  **Non-Linear Data Structures**: Data elements are not arranged sequentially. There is a hierarchical relationship between elements.
    *   **Trees**: Hierarchical structure (e.g., File systems).
    *   **Graphs**: Network structure (e.g., Social networks, Maps).

---

## 2. User-Defined Data Types (Classes in C++)

In C++, we often need data types that are more complex than just an `int` or `char`. We want to group related data together. This is where **Classes** come in.

A `class` allows us to create a **User-Defined Data Type**. It acts as a blueprint for creating objects.

### Example: A Complex Number
A complex number has a real part and an imaginary part. We can define a type `Complex` using a class:

```cpp
#include <iostream>
using namespace std;

class Complex {
public:
    int real;
    int imag;

    // Constructor to initialize
    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    // Creating a variable of type 'Complex'
    Complex c1(5, 10); 
    c1.display(); // Output: 5 + 10i
    
    return 0;
}
```

Here, `Complex` is now a valid data type, just like `int` or `double`, but we defined it!

---

## 3. Creating a Node

The building block of many dynamic data structures (like Linked Lists, Trees, Graphs) is a **Node**.

A Node typically contains two things:
1.  **Data**: The actual value we want to store.
2.  **Pointer**: A reference (address) to the next node in the sequence.

### Why use a Class for a Node?
Since a Node needs to hold both an integer (data) and a pointer (address), a simple primitive type won't work. We need a user-defined type.

### C++ Implementation of a Node

```cpp
class Node {
public:
    int data;       // Data part
    Node* next;     // Pointer to the next Node

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr; // Initially, it points to nothing
    }
};
```

*   `int data`: Stores the value.
*   `Node* next`: This is a pointer of type `Node`. It holds the address of another `Node` object. This is called a **Self-Referential Structure**.

---

## 4. Introduction to Linked Lists

A **Linked List** is a linear data structure where elements are not stored at contiguous memory locations. The elements are linked using pointers.

*   **Head**: The first node of the linked list.
*   **Tail**: The last node, which points to `nullptr`.

### Visualizing a Linked List
`[Data|Next] -> [Data|Next] -> [Data|Next] -> NULL`

### Creating a Simple Linked List in C++

Let's link two nodes together to form a small chain.

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int main() {
    // 1. Create the first node (Head)
    Node* head = new Node(10); 

    // 2. Create the second node
    Node* second = new Node(20);

    // 3. Link them: head's next should point to second
    head->next = second;

    // 4. Create a third node
    Node* third = new Node(30);

    // 5. Link second to third
    second->next = third;

    // Now we have: 10 -> 20 -> 30 -> NULL

    // Let's print the list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
```

### Key Takeaways
1.  **Dynamic Memory**: We use `new` to create nodes in the heap memory.
2.  **Pointers**: We use pointers to connect nodes.
3.  **Traversal**: We start from the `head` and move to `next` until we reach `nullptr`.

This is the foundation of ADSA. From here, you can build Doubly Linked Lists, Circular Lists, Stacks, Queues, and Trees!
