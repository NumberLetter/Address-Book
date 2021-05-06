#ifndef __PHONE_H__
#define __PHONE_H__
/*  Author: Kingsley Liu
 *  Program: Phone Directory
 *  This header file declares the functions, variables, and class for phone.cpp
 *  11 April, 2021
 */



 #include <stdlib.h>
 #include <iostream>
 #include <string>
 #include <cstring>
 #include <vector>
 #include <sstream>
 #include <fstream>
 #include <algorithm>
 #include <cmath>
 #include <array>
 #include <map>
 #include <set>
 #include <queue>
 #include <bits/stdc++.h>


class Node
{
    private:
        int data;
        Node* left;
        Node* right;

    public:
        Node(int data);
        ~Node();

    friend class Phone;
};

class Phone
{

    private:
        Node* root; // Root of node
        Node* temp; // Temporary node

        Node* ptr, *ptr1, *ptr2;     // Node pointer

        std::string address;    // Stores the address
        std::string fname;  // File name
        std::string fname2;     // City file
        double zip;  // Name of the business

        double radius;  // Within a certain radius
        double user_distance;   // user's range of radius

        int index;  // Stores the vector index

        //vector to store pait of cordinates                                                    // Stack for visualization
        std::vector<std::pair <double, double>> cord;                                            // Dynamic array

        std::vector<std::pair <double, double>> user_coord;  // Store user data                  // User data
        double user_lat, user_long;                         // Store user's long and lat


        std::vector<std::pair<double, int>> distance;   // Stores the calculated distance;      // Try Map & Set

        // latitude, long

        std::vector<std::string> street;




        // Sets and maps data structure

        std::map<std::string, std::pair<double, double> > city_map;
        std::string city_file;
        std::vector <std::string> city_name;
        std::vector <double> city_lat;
        std::vector <double> city_lon;

        // Queue
        //Output the closest distance from users city
        //output closest resturaunt to the city, address of the resturaunt from read file,
        std::vector <std::string> resturaunt_address;
        //for second one std::vector<std::pair<double, int>> distance;
        std::priority_queue <  std::pair < double, int >  > p_queue;



    public:

        Phone(std::string fname, std::string fname2);  // Constructor
        Phone();


        // Destructor
        ~Phone();

        // Write to CSV file
        void dataToCSV();


        // Read Priority Queue
        void write_p_queue();

        // Display the data
        void display_data();

        // Ask user for input
        void user_input();

        // Check for address
        bool valid_address(std::string);


        // Read CSV file
        void read_CSV(std::string fname);

        // Read CSV map
        void read_CSV_map(std::string fname2);

        //city is unique, city name as key

        // Calculates the distance between two business locations
        double get_distance(double, double, double, double);

        // search the location, if data is available, otherwise, insert data
        //void search();

        // ask user for data
        //void insert();

        void upperCase(std::string strToConvert);


};

#endif
