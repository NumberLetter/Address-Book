/*  Author: Kingsley Liu
 *  Program: Phone Directory
 *  This phone.cpp file checks for the nearby competition of similar businesses
 *  11 April, 2021
 */

#include "phone.h"

// Constructor
Phone::Phone(std::business_name)
{
    this->business_name = business_name;
    search(business_name);  // Search if the business is in the CSV file
}

void Phone::upperCase(string& strToConvert)
{
    for(unsigned int i = 0; i < strToConvert.length(); i++)
    {
        strToConvert[i] = toupper(strToConvert[i]);
    }
}


int main(int argc, char ** argv)
{
    std::string b_name;

    std::cout << "Please enter the business name: ";
    std::cin >> b_name;

    Phone(b_name);
}