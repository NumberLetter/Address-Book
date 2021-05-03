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
 #include <vector>
 #include <sstream>
 #include <fstream>
 #include <algorithm>
 #include <cmath>
 #include <array>


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

        std::string fname;  // File name
        std::string zip;  // Name of the business

        double radius;  // Within a certain radius


    public:

        Phone(std::string fname);  // Constructor
        Phone();


        // Destructor
        ~Phone();

        // Write to CSV file
        //void dataToCSV();

        void user_input();

        // Read CSV file
        void read_CSV(std::string fname);

        // Calculates the distance between two business locations
        double distance(double x1, double x2, double y1, double y2);

        // search the location, if data is available, otherwise, insert data
        //void search();

        // ask user for data
        //void insert();

        void upperCase(std::string strToConvert);


};

#endif