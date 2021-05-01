/*  Author: Kingsley Liu
 *  Program: Phone Directory
 *  This phone.cpp file checks for the nearby competition of similar businesses
 *  11 April, 2021
 */

#include "Phone.h"

// Constructor
Phone::Phone(business_name)
{
    this->business_name = business_name;
    read_csv(std::string fname);

    search(business_name);  // Search if the business is in the CSV file
}

void Phone::upperCase(string& strToConvert)
{
    for(unsigned int i = 0; i < strToConvert.length(); i++)
    {
        strToConvert[i] = toupper(strToConvert[i]);
    }
}

void Phone::read_CSV(std::string fname)
{
    //opening the file
    std::ifstream input(fname);
    //dynamic 2D array
    //int arr[][];
    //vector to store pait of cordinates
    std::vector<std::pair<int, int>> cord;
    //string to store the addresses
    std::string address;

    //interger to store the latitude
    int lat;
    //interger to store the longitude
    int lon;
    

    std::string line;

    while(std::getline(input, line)){
        //reads line
        std::stringstream ss(line);
        std::string temp;
        std::getline(ss, temp, ',');
        address = temp;
        //seperates collumns
        //gets latitude
        std::getline(ss, temp, ',');
        lat = std::stoi(temp);
        //gets longitude
        std::getline(ss, temp, ',');
        lon = std::stoi(temp);
        //pushes pair of lon and lat
        cord.push_back(std::make_pair(lat, lon));
    }
    input.close();
    for(int i = 0; i < 10; i++){
        std::cout<< cord[i].first << cord[i].second << "\n";
    }
    // queue<string> buisnesses;
    // //store pair into 2d array = dynamic arrays
    // queue<pair<int, int>> cordinate;
    // //store vector into queue
    // //maping for cordinates
    // //array inside queue inside map
    // //array O(n), queue = O?, map = O?
    // //multiply bc inside of each other
    // int integer1;
    // int integer2;
    // fname.open(fname_name);

    // string name;
    // string lon;
    // string lat;

    // while(getline(file, name, ',')){

    //     buisnusses.push_back(name);
    //     outfile.write(buisnesses);
         
    //     getline(file, lon, ',');
    //     getline(file, lat, ',');

    //     //changd to integer
    //     integer1 = stoi(lon);
    //     integer2 = stoi(lat);
    //     cordinate.push_back(lon, lat);
    // }

}


int main(int argc, char ** argv)
{
    
    std::string b_name;

    std::cout << "Please enter the business name: ";
    std::cin >> b_name;

    Phone(b_name);
}
