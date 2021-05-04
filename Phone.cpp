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

    user_input();   // Ask for the zip code

    // Display data
    display_data();

    //search(business_name);  // Search if the business is in the CSV file
}
//Destcructor
Phone::~Phone(){

}
void Phone::user_input()
{
    // If city not in csv file,
    // ask user to input the city, longitude, and latitude

    // std::cout << "What is your zip code: ";
    // std::cin >> this->zip;

    // Get entire line
    std::cout << "What is your address: ";
    std::getline(std::cin, this->address);


    if(valid_address(this->address))
    {
        std::cout << "Enter a search radius(miles) for the search range: ";
        std::cin >> this->radius;

        // Do the calculation again here
    }
    else
    {
        // Check for valid input
        do
        {
            std::cout << "Please enter the latitude: ";
            std::cin >> this->user_lat;
        } while(user_lat >= 90.0 user_lat >= -90);

        // Stores the user data in the vector of pairs
        user_coord[0].first = user_lat;

        // Check for valid input
        do
        {
            std::cout << "Please enter the longitude: ";
            std::cin >> this->user_long;
        } while(user_long >= 180 && user_long >= -180);

        // Stores the user data in the vector of pairs
        user_coord[0].second = user_long;


        for(int i = 0; i < street.size(); i++)
        {
            this->user_distance = get_distance(user_coord[0].first, user_coord[0].second, cord[i].first, cord[i].second);

            if(user_distance < this->radius)
            {
                // Add the locations that is within the user's radius
                distance[i] = get_distance(user_coord[0].first, user_coord[0].second, cord[i].first, cord[i].second);
            }

        }


    }
    // Upper case
    std::transform(this->address.begin(), this->address.end(), this->address.begin(), ::toupper);
    // std::cout << this->address <<std::endl;



}

bool Phone::valid_address(std::string address)
{
    std::string tmp_address;

    bool valid;

    for(int i = 0; i < street.size(); i++)
    {
        tmp_address = street[i];

        // std::cout << "Street size: " <<street.size() << std::endl;
        std:: cout << tmp_address << std::endl;
        // std::cout << address << std::endl;
        int res = tmp_address.compare(address);
        if(res == 0)
        {
            // std::cout << "Same address!" << std::endl;
            valid = true;
            this->index = i;
        }
        else
        {
            // std::cout << "Not the same address!" << std::endl;
            valid = false;
        }
    }
    return valid;
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

    std::cout << "User Location: " << user_coord[0].first << ", " << user_coord[0].second << std::endl;
    std::cout << "Data Location: " << cord[2].first << ", " << cord[2].second << std::endl;

    // std::cout << "Distance: " << get_distance(cord[1].first, cord[2].second, cord[2].first, cord[2].second) << std::endl;
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


