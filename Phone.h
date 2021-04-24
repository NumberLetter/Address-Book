/*  Author: Kingsley Liu
 *  Program: Phone Directory
 *  This header file declares the functions, variables, and class for phone.cpp
 *  11 April, 2021
 */

 #ifndef __PHONE_H__
 #define __PHONE_H__

 #include <stdlib.h>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <sstream>
 #include <fstream>
 #include <algorithm>
 #include <cmath>

class Node
{
    private:
        int data;
        Node* left;
        Node* right;

    public:
        Node(int data);
        ~Node();

    friend class phone;
};

class phone
{

    private:
        Node* root; // Root of node
        Node* temp; // Temporary node

        Node* ptr, *ptr1, *ptr2;     // Node pointer

        std::string fname;  // File name
        std::string business_name;  // Name of the business

    public:

        Phone(std:;string business_name);  // Constructor
        Phone();

        // Destructor
        ~Phone();

        // Write to CSV file
        void dataToCSV();

        // Read CSV file
        void read_CSV(std::string fname);

        // Calculates the distance between two business locations
        double distance(ptr1, ptr2);

        // search the location, if data is available, otherwise, insert data
        void search();

        // ask user for data
        void insert();

        void upperCase(string& strToConvert);


}