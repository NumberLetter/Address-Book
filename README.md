# Address-Book

Project written in C++
Data saved into a CSV file

CSC-212 Final Project: Finds restaurants within a certain radius (miles) from the city's latitude and longitude.

The project focuses on concepts on data structures and abstractions. 

# Compile the program

 1. Download Phone.cpp, Phone.h, Restaurant.csv, and City.csv
 2. To compile the program:
    **g++ -std=c++11 -Wall Phone.cpp -o calc && ./calc Restaurant.csv City.csv**
 3. The program will output a **Points.csv** file. 
 4. Enter the file to visual graph:
    https://www.csvplot.com/

# Data Strucutres & Algorithms

For the project, we decided to use **Vector, Priority Queue, Stack, and Map & Set**.

The **vector** is similar to a dynamic array. It can expands its memory at run time and always store elements in contiguous memory location. When the program reads a CSV file, all the data is stored in a vector. The elements will remain in the same order when they are inserted. Reallocation of new elements is done implicitly. The simplicity of vectors allow the program to find the index quickly and keeps track of the size at all times. 

A **Priority Queue** is a type of container adapter that processes only the highest priority element. It follows the same rule, First-in-First-out (FIFO), as a normal queue, but the elements are removed based on priority. The element with the highest priority is the first one to be removed from the priority queue. The unique function **insert_with_priority** adds an element with priority. In the program, the restaurants with the shortest distance takes priority. The output from a priority queue will show all the restaurants from least to greast distance.

A **stack** is the opposite of a queue. It follows the rule Last-in-First-out (LIFO). Stack uses only one end to add (push) and remove (pop) elements. In the program's usuage, it scans the data from left to right aand marks the operator precedence. When an operator is encountered, operands are popped out and the operation is performed. When the expression is evaluated by the stack, the final result is at the top of the stack. 

A **Map & Set** is used to store key value pairs. A map is similar to a dictionary (Only one unique word, but contains different definitions).The program uses a unique key from the user which is the city's name. Then, the map will associate the stored pair of coordinates values along the key. The performance of a map is implemented as some sort of self-balancing binary tree. It is relatively simple to look up the city name in a narrow range (Constant time).   

# Analysis (Time Complexity)
...







