# CS 300 Portfolio

## Reflection on Projects One and Two

**What was the problem you were solving in the projects for this course?**  
The advisors at ABCU needed a program that could load course data from a file, print a sorted list of all the courses in the Computer Science department, and show the title plus prerequisites for any single course they asked about.

**How did you approach the problem? Consider why data structures are important to understand.**  
I started by looking at what the advisors actually needed — a sorted list and fast lookups. Before this class I had no idea how much difference the choice of data structure makes. A vector is simple but slow to sort every time. A hash table is fast for finding things but hard to print in order. A binary search tree keeps everything sorted automatically, so I went with that one because it solved both problems at the same time.

**How did you overcome any roadblocks you encountered while going through the activities or project?**  
The biggest roadblock was getting the code to compile and run on my Mac. I kept getting linker errors and infinite loops when I typed the wrong thing for the menu. I fixed it by adding extra input checks and making sure the tree didn’t add the same course twice. I also spent time fixing the file reading part until it worked cleanly.

**How has your work on this project expanded your approach to designing software and developing programs?**  
This project taught me to start with the actual problem first instead of just picking a data structure because it looks cool. I now think about speed, memory use, and what the user really needs before I start writing code.

**How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**  
I started adding more simple comments so anyone can understand what each part does. I use clear variable names and break the code into small functions. These changes make the program much easier to read, fix, and reuse later.

Submitted by: Christian
