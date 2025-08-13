# In first class we study about :
Notes Links: 
1. https://www.geeksforgeeks.org/dsa/what-is-data-structure-types-classifications-and-applications/
2. https://www.geeksforgeeks.org/dsa/dsa-tutorial-learn-data-structures-and-algorithms/


## what is DSA ?
Data Structure is a storage that is used to store and organise data. It is the way of arranging the data so that we can access it directly.
## Type of data structure ?
1. Linear Data Structure
2. Non-Linear Data Sttructure
## Linear Data Structure
the elements are arranged in a sequence order
example : array,stacked data structure,

![cool
logo](https://media.geeksforgeeks.org/wp-content/uploads/20220520182504/ClassificationofDataStructure-660x347.jpg)

## Non Linear data structure
we cannot placed elements sequencially
example : Tree & Graphs

### ARRAY
An array is a linear data structure and it is a collection of element of same data type stored at contiguous memory locations.
It offers mainly the following advantages.

- Random Access: i-th elements can be accessed in O(1) Time as we have the base address and every element is of same size.
- Cache Friendliness: Since elements are stored at contiguous locations, we get the advantage of locality of reference.

Different applications of an array are as follows:

#### Arrays efficiently manage and store database records.

It helps in implementing sorting algorithm.
It is also used to implement other data structures like Stacks, Queues, Heaps, Hash tables, etc.
An array can be used for CPU scheduling.

### Linked list Data Structure
A linked list is a linear data structure in which elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers as shown in the below image.

#### Applications of the Linked list 

- Linked lists are used to implement other data structures like stacks, queues, etc.
- It is used for the representation of sparse matrices.
- It is used in the linked allocation of files.
- Linked lists are used to display image containers. Users can visit past, current, and next images.
- They are used to perform undo operations.

Ques: Difference BTW array and linked list?

### Stack Data Structure
Stack is a Linear Data Structure that follows LIFO(Last in First out) Principle i.e., entering and retrieving data is possible from only one end. The entering and retrieving of data is also called push and pop operation in a stack.

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221219100314/stack.drawio2.png)

#### Applications of Stack

Different applications of Stack are as follows:

- The stack data structure is used in the evaluation and conversion of arithmetic expressions.
- It is used for parenthesis checking and string reversal.
- A memory stack is also used for processing function calls.
- The stack is used in virtual machines like JVM.

### Queue Data Structure
Queue is a linear data structure that follows First In First Out(FIFO) principle i.e. the data item stored first will be accessed first. In this, entering is done from one end and retrieving data is done from other end. An example of a queue is any queue of consumers for a resource where the consumer that came first is served first.

Operations : Insertion(enqueue) & Deletion (dequeue)

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221213113312/Queue-Data-Structures.png)

#### Applications of Queue: 

Different applications of Queue are as follows:

- Queue is used for handling website traffic.
- It helps to maintain the playlist in media players.
- It helps in serving requests on a single shared resource, like a printer, CPU task scheduling, etc.
- Queues are used for job scheduling in the operating system.

#### --- Circular Queue Implementation ---

class CircularQueue:
    def __init__(self, size):
        self.size = size
        self.queue = [None] * size
        self.front = -1
        self.rear = -1

    def enqueue(self, value):
        if (self.rear + 1) % self.size == self.front:
            print("Queue is full!")
            return
        if self.front == -1:
            self.front = 0
        self.rear = (self.rear + 1) % self.size
        self.queue[self.rear] = value

    def dequeue(self):
        if self.front == -1:
            print("Queue is empty!")
            return None
        result = self.queue[self.front]
        if self.front == self.rear:
            self.front = self.rear = -1  # Queue is now empty
        else:
            self.front = (self.front + 1) % self.size
        return result

#### Example usage
cq = CircularQueue(3)
cq.enqueue(10)
cq.enqueue(20)
cq.enqueue(30)  # Queue is full after this
cq.dequeue()
cq.enqueue(40)  # Wraps around

print("Circular Queue State:", cq.queue)

#### --- Bitwise Swap Without Temporary Variable ---

a = 5  # 0101 in binary
b = 9  # 1001 in binary

print(f"Before swap: a={a}, b={b}")

a = a ^ b
b = a ^ b
a = a ^ b

print(f"After swap: a={a}, b={b}")

### Tree Data Structures (Not in Syllabus)
A tree is a non-linear and hierarchical data structure where the elements are arranged in a tree-like structure. In a tree, the topmost node is called the root node. Each node contains some data, and data can be of any type. It consists of a central node, structural nodes, and sub-nodes which are connected via edges. Different tree data structures allow quicker and easier access to the data as it is a non-linear data structure.

![](https://media.geeksforgeeks.org/wp-content/uploads/20220518124202/TreeBasicTerminology.png)

#### Applications of Tree:

- Heap is a tree data structure that is implemented using arrays and used to implement priority queues.
- B-Tree and B+ Tree are used to implement indexing in databases.
- Syntax Tree helps in scanning, parsing, generation of code, and evaluation of arithmetic expressions in Compiler design.
- Spanning trees are used in routers in computer networks.
- Domain Name Server also uses a tree data structure

### Binary Search Tree Data Structures (Not is syllabus)
A Binary Search Tree (or BST) is a data structure used for organizing and storing data in a sorted manner. Each node in a Binary Search Tree has at most two children, a left child and a right child, with the left child containing values less than the parent node and the right child containing values greater than the parent node. This hierarchical structure allows for efficient searching, insertion, and deletion operations on the data stored in the tree.

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221215114732/bst-21.png)

#### Applications of Binary Search Tree:

A Self-Balancing BST maintains a sorted stream of data in RAM, useful for tracking online orders by price and querying item counts above or below a given cost.
It enables a doubly-ended priority queue, supporting both extractMin() and extractMax() in O(log n) time, unlike a Binary Heap.
Many algorithmic problems, like counting smaller elements on the right or finding the smallest greater element, benefit from a Self-Balancing BST.
TreeMap and TreeSet in Java, and set and map in C++, are implemented using Red-Black Trees, a type of Self-Balancing BST.

### Graph Data Structure
A graph is a non-linear data structure that consists of vertices (or nodes) and edges. It consists of a finite set of vertices and set of edges that connect a pair of nodes. The graph is used to solve the most challenging and complex programming problems. It has different terminologies which are Path, Degree, Adjacent vertices, Connected components, etc.
![](https://media.geeksforgeeks.org/wp-content/uploads/20220518124302/undirectedgraph.png)

### Applications of Graph:

- The operating system uses Resource Allocation Graph.
- Also used in the World Wide Web where the web pages represent the nodes. 
- One of the most common real-world examples of a graph is **Google Maps** where cities are located as vertices and paths connecting those vertices are located as edges of the graph.
- A social network is also one real-world example of a graph where every person on the network is a node, and all of their friendships on the network are the edges of the graph.

## NOTE
- Learn defination for viva
- and its application
