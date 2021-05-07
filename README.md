# Address-Book

Project written in C++ Data saved into a CSV file

CSC-212 Final Project: Finds restaurants within a certain radius (miles) from the city's latitude and longitude.

The project focuses on concepts on data structures and abstractions.

# Compile the program

1. Download Phone.cpp, Phone.h, Restaurant.csv, and City.csv
2. To compile the program: **g++ -std=c++11 -Wall Phone.cpp -o calc && ./calc Restaurant.csv City.csv**
3. The program will output a Points.csv file.
4. Enter the file to visual graph: https://www.csvplot.com/

# Code overview :

Upon compiling, the user is asked to input a city name, a radius, and a location. Then, we read a csv file containing resturaunt adresses and the latitude and longitude of each resturaunt. These values will be stored in a dynamic array. Next, the distance from the user's input location is calculated and checked to see if the resturaunt is within the distance. We push those values into a priority queue in order to sort them by the furthest distance away from the user to the closest. Finally, we output elements from the priority queue into a csv file for the user to read. 

# Data Strucutres & Algorithms

For the project, we decided to use a **Dynamic Array/Vector**, **Priority Queue**, and **Map&Set**.

**Dynamic Arrays/Vector : Desired demonstration of knowledge: Mastery**
The vector is similar to a dynamic array. It can expands its memory at run time and always store elements in contiguous memory location.
When the program reads a CSV file, all the data is stored in a vector. The elements will remain in the same order when they are inserted.
Reallocation of new elements is done implicitly. The simplicity of vectors allow the program to find the index quickly and keeps track of
the size at all times.

**Priority Queue : Desired demonstration of knowledge : Mastery**
A Priority Queue is a type of container adapter that processes only the highest priority element. It follows the same rule,
First-in-First-out (FIFO), as a normal queue, but the elements are removed based on priority. The element with the highest priority
is the first one to be removed from the priority queue. The unique function insert_with_priority adds an element with priority.
In the program, the restaurants with the shortest distance takes priority. The output from a priority queue will show all the
restaurants from least to greatest distance in order to simplify it for the user so they dont need to do additional work.


**Maps & Set : Desired demonstration of knowledge : Mastery**
A Map & Set is used to store key value pairs. A map is similar to a dictionary (Only one unique word,
but contains different definitions).The program uses a unique key from the user which is the city's name.
Then, the map will associate the stored pair of coordinates values along the key. The performance of a map is
implemented as some sort of self-balancing binary tree. It is relatively simple to look up the city name in a narrow
range (Constant time).
why set wasn't used

# Analysis (Time Complexity)

**Time complexity of read_CSV**

The time complexity of the function read_CSV which usees dynamic arrays is O(n)
where n is the number of elements in the csv file that is passed in. This program reads
a file using a while loop of n lines, line by line, causing it to have a linear time complexity.



**Time complexity of dataToCSV**

The time complexity of the datatoCSV file is O(n) with the n being the size of the distance vector. 
This is because when going through a vector, and writing its values to a file using a for loop and going
through each individual element, the time complexity will be linear as there are no other loops and because
it goes through each index once.




**Time complexity of write_p_queue**

For the write_p_queue where the data from the distance vector is pushed into a priority queue and sorted in there. 
The loop traverses through each index of the distance vector and there are n items being added to the priority queue and getting
sorted. The time complexity is going to be O(nlogn) for that portion. Then, there is a for loop which runs n times and writes 
the contents of the priority queue to a file named "ofile" which has a time complexity of O(1). This leads the function to have
a total time complexity of O(nlogn + 1) - > O(nlogn).

** Group : Kang (Kingsley) Liu & Suneal (Sunny) Lall **

# Topic Overview

We wish to aquire **mastery** in the following topics of **Priority Queues**, **sets& maps**, and **Dymanic arrays** as we beleive we have chosen the best data structures the data structures for the application. Using a **priotity queue** to write to a file while outputting the furthest to closest distance from a resturaunt to a users coordinates is a problem that many people have daily. When a person is hungry and doesn't know where to go, chances are, they will open some application to find food places near them, similar to what we did in our program. Our final project also demonstrates mastery in **sets&maps** as we correctly use the data structure of maps to store the values of both a city and a pair of latitude and longitude. Maps were the best choice here because unlike sets where you can only store keys, maps allow us to store the key's value pairs where the unique key is the city name and value being a std::pair <double, double> containing the latitude and longitude. Finally we acheived mastery in **Dynamic arrays** because the data can be easily expanded and accessed through an index. With the size of the inFile being unknown, a dynamic array was the best choice as you don't need to hard code the size in and can aquire the size by using dynamic_array.size().


