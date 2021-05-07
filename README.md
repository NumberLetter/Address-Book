Address-Book

Project written in C++ Data saved into a CSV file

CSC-212 Final Project: Finds restaurants within a certain radius (miles) from the city's latitude and longitude.

The project focuses on concepts on data structures and abstractions.

Compile the program

Download Phone.cpp, Phone.h, Restaurant.csv, and City.csv
To compile the program: g++ -std=c++11 -Wall Phone.cpp -o calc && ./calc Restaurant.csv City.csv
The program will output a Points.csv file.
Enter the file to visual graph: https://www.csvplot.com/
Data Strucutres & Algorithms

For the project, we decided to use Vector, Priority Queue, Stack, and Map & Set.

The vector is similar to a dynamic array. It can expands its memory at run time and always store elements in contiguous memory location.
When the program reads a CSV file, all the data is stored in a vector. The elements will remain in the same order when they are inserted.
Reallocation of new elements is done implicitly. The simplicity of vectors allow the program to find the index quickly and keeps track of
the size at all times.

A Priority Queue is a type of container adapter that processes only the highest priority element. It follows the same rule,
First-in-First-out (FIFO), as a normal queue, but the elements are removed based on priority. The element with the highest priority
is the first one to be removed from the priority queue. The unique function insert_with_priority adds an element with priority.
In the program, the restaurants with the shortest distance takes priority. The output from a priority queue will show all the
restaurants from least to greatest distance in order to simplify it for the user so they dont need to do additional work.

A stack is the opposite of a queue. It follows the rule Last-in-First-out (LIFO). Stack uses only one end to add (push) and
remove (pop) elements. In the program's usuage, it scans the data from left to right and marks the operator precedence. When
an operator is encountered, operands are popped out and the operation is performed. When the expression is evaluated by the stack,
the final result is at the top of the stack.

A Map & Set is used to store key value pairs. A map is similar to a dictionary (Only one unique word,
but contains different definitions).The program uses a unique key from the user which is the city's name.
Then, the map will associate the stored pair of coordinates values along the key. The performance of a map is
implemented as some sort of self-balancing binary tree. It is relatively simple to look up the city name in a narrow
range (Constant time).
why set wasn't used

Analysis (Time Complexity)

Time complexity of read_CSV

The time complexity of the function read_CSV which usees dynamic arrays is O(n)
where n is the number of elements in the csv file that is passed in. This program reads
a file using a while loop of n lines, line by line, causing it to have a linear time complexity.



Time complexity of dataToCSV

The time complexity of the datatoCSV file is O(n) with the n being the size of the distance vector. 
This is because when going through a vector, and writing its values to a file using a for loop and going
through each individual element, the time complexity will be linear as there are no other loops and because
it goes through each index once.




Time complexity of write_p_queue

For the write_p_queue where the data from the distance vector is pushed into a priority queue and sorted in there. 
The loop through each index of the distance vector and because there are n items being added to the priority queue and being
sorted, the time complexity is going to be nlogn for that portion. Then, there is a for loop which runs n times and writes 
the contents of the priority queue to a file named "ofile" which had a time complexity of n. This leads the function to have
a total time complexity of O(nlogn+n)





