# Data-Structure
# **Data Structures Implementation in C**  

Welcome to the **Data Structures** repository! 🚀 This reposatory contains implementations of various data structures in **C**, along with test cases to verify their functionality.  

## **Features**  
✅ **Comprehensive Implementations** – Includes linked lists, stacks, queues, trees, and searching/sorting algorithms.  
✅ **Efficient and Optimized** – Written with performance and clarity in mind.  
✅ **Modular Code** – Organized into different folders for easy navigation.  
✅ **Test Cases Included** – Each data structure has test files to validate its correctness.  

## **Technologies Used**  
- **C Programming Language** – Core language for implementation.  
- **GCC Compiler** – Used for compiling and testing the code.  

## **Installation & Usage**  

### **1️⃣ Clone the Repository**  
```bash
git clone https://github.com/Akmalkhan0/Data-Structure.git
cd Data-Structures
```

### **2️⃣ Compile & Run**  
To compile any C program, use:  
```bash
gcc -o output_file source_file.c
./output_file
```
For example, to test **binary search**:
```bash
gcc -o binary_search searching/binary_search.c
./binary_search
```

### **3️⃣ Run Test Cases**  
```bash
gcc -o test_list linked_list/single/test_list1.c linked_list/single/list1.c
./test_list
```
Modify paths as needed to test different data structures.

---

## **Folder Structure**  
```bash
Data-Structures/
├── linked_list/
│   ├── circular/          # Circular linked list
│   │   ├── list.c
│   │   ├── test_list.c
│   ├── double/            # Doubly linked list
│   │   ├── list1.c
│   │   ├── test_list.c
│   ├── single/            # Singly linked list
│       ├── list1.c
│       ├── test_list1.c
│
├── queue/
│   ├── dynamic/           # Dynamic queue
│   ├── growable/          # Growable queue
│   ├── linear/            # Linear queue
│   ├── static_circular/   # Static circular queue
│   ├── dequeue/           # Double-ended queue
│   ├── linear_queue/      # Another linear queue
│
├── searching/             # Search algorithms
│   ├── binary_search.c
│   ├── linear_search.c
│
├── sorting/               # Sorting algorithms
│   ├── insert_sort.c
│   ├── merge_sort.c
│   ├── quick_sort.c
│
├── stack/
│   ├── dynamic/           # Dynamic stack
│   ├── static/            # Static stack
│
├── tree/                  # Tree data structures
│   ├── tree.c
│   ├── test-tree.c
│   ├── README.md
│
├── .gitignore             # Git ignore file
├── LICENSE                # License file
└── README.md              # Project documentation
```

---

## **Contributing**  
Contributions are welcome! If you find bugs or improvements, feel free to submit a pull request.  

1. **Fork the repository**  
2. **Create a new branch**  
3. **Commit your changes**  
4. **Push the branch**  
5. **Create a pull request**  
6. **Also Add comments to the Problems**  

---

🚀 **Happy Coding!** 🚀  

---

Let me know if you need any modifications! 😊
