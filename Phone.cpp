/*  Author: Kingsley Liu
 *  Program: Phone Directory
 *  This phone.cpp file checks for the nearby competition of similar businesses
 *  11 April, 2021
 */

#include "Phone.h"

// Constructor
Phone::Phone(std::string fname){

    // Read the file
    read_CSV(std::string (fname));

    // Display data
    display_data();
    // user_input();   // Ask for the zip code

    //search(business_name);  // Search if the business is in the CSV file
}
//Destcructor
Phone::~Phone(){

}
void Phone::user_input()
{
    // If city not in csv file,
    // ask user to input the city, longitude, and latitude

    std::cout << "What is your zip code: ";
    std::cin >> this->zip;

    std::cout << "Enter a search radius(miles) for the search range: ";
    std::cin >> this->radius;
}

void Phone::upperCase(std::string strToConvert)
{
    for(unsigned int i = 0; i < strToConvert.length(); i++)
    {
        strToConvert[i] = toupper(strToConvert[i]);
    }
}

double Phone::get_distance(double x1, double x2, double y1, double y2)
{
    double distance;

    double d1 = std::pow(x2-x1, 2.0);
    double d2 = std::pow(y2-y1, 2.0);
    // Distance formula
    distance = std::sqrt(d1 - d2);

    double converted_value = 0.000621 * distance;
    // Convert nautical mile to miles unit
    double mile = converted_value + distance;

    return mile;
}

void Phone::display_data()
{
    for(int i = 0; i < cord.size(); i++)
    {
        std::cout<< street[i] << ", " << cord[i].first << ", " << cord[i].second << "\n";
    }

    std::cout << "Location 1: " << cord[1].first << ", " << cord[1].second << std::endl;
    std::cout << "Location 2: " << cord[2].first << ", " << cord[2].second << std::endl;

    std::cout << "Distance: " << get_distance(cord[1].first, cord[2].second, cord[2].first, cord[2].second) << std::endl;
}

void Phone::read_CSV(std::string fname)
{
    //opening the file
    std::ifstream input(fname);

    //string to store the addresses
    std::string address;

    //interger to store the latitude
    double lat;
    //interger to store the longitude
    double lon;


    std::string line;

    while(std::getline(input, line)){
        //reads line
        std::stringstream ss(line);
        std::string temp;

        std::getline(ss, temp, ',');
        address = temp;
        street.push_back(address);
        //seperates collumns
        //gets latitude
        std::getline(ss, temp, ',');
        lat = stod(temp);
        //gets longitude
        std::getline(ss, temp, ',');
        lon = stod(temp);
        //pushes pair of lon and lat
        cord.push_back(std::make_pair(lat, lon));
    }

    input.close();
}

int main(int argc, char ** argv)
{

    std::string name = argv[1];

    Phone read(name);

}


