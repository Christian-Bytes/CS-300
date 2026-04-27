# CS-300
# CS 300 - Data Structures and Algorithms Portfolio

## Project One & Project Two Artifacts

- **Project One Artifact**: Runtime and memory analysis of data structures (Vector, Hash Table, Binary Search Tree)
- **Project Two Artifact**: Working C++ program (ProjectTwo.cpp) that loads courses and prints them in alphanumeric order using a Binary Search Tree

---

## Reflection Questions

**What was the problem you were solving in the projects for this course?**  
The advisors at ABCU needed a program that could load course data from a file, print a sorted list of all courses, and show the title and prerequisites for any single course. The main problem was choosing the best data structure to make these tasks fast and easy.

**How did you approach the problem? Consider why data structures are important to understand.**  
I started by looking at what the advisors actually needed: a sorted list and fast lookups. I learned that data structures are important because they decide how fast the program runs. A vector is simple but slow to sort, a hash table is fast for searching but hard to sort, and a binary search tree keeps everything sorted automatically. I picked the binary search tree because it solved both problems at the same time.

**How did you overcome any roadblocks you encountered while going through the activities or project?**  
The biggest roadblock was getting the code to compile on my Mac. I kept getting linker errors and infinite loops. I fixed them by carefully checking the main function, adding input validation, and making sure the file reading worked correctly. I also had trouble with duplicates in the tree, so I added a check before inserting.

**How has your work on this project expanded your approach to designing software and developing programs?**  
This project showed me that I should always start with the problem first, not just pick a data structure because it looks cool. I now think about speed, memory, and what the user actually needs before writing code. I also learned that good comments and simple code make programs much easier to fix later.

**How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**  
I started adding more comments so anyone can understand what each part does. I used clear variable names and broke the code into small functions. I also made sure the program handles bad input without crashing. These changes make the code much easier to read, fix, and reuse in the future.

---

Submitted by: Christian
