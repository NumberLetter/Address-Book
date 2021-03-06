/*  Author: Kingsley Liu
 *  Program: Phone Directory
 *  This phone.cpp file checks for the nearby competition of similar businesses
 *  11 April, 2021
 */

#include "Phone.h"

// Constructor
Phone::Phone(std::string fname, std::string fname2){

    // Read the file
    read_CSV(std::string (fname));

    //user_input();   // Ask for the zip code
    read_CSV_map(fname2);

    user_input();

    // Display data
    display_data();

    // Write the csv file
    dataToCSV();

    // Write the priority file
    write_p_queue();
}
//Destcructor
Phone::~Phone(){

}
void Phone::user_input()
{
    // Get entire line
    std::cout << "What is your city: ";
    std::getline(std::cin, this->address);

    do
    {
        std::cout << "Enter a search radius(miles) for the search range: ";
        std::cin >> this->radius;

    }while(this->radius < 0);


    // Check for valid input
    do
    {
        // Ask user for latitude
        std::string user_tmp;
        std::cout << "Please enter the latitude: ";
        std::cin >> user_tmp;
        this->user_lat = std::stod(user_tmp);

        // Ask user for longitude
        std::cout << "Please enter the longitude: ";
        std::cin >> user_tmp;
        this->user_long = std::stod(user_tmp);

        user_coord.push_back(std::make_pair(this->user_lat, this->user_long));

    }while(this->user_lat >= 90.0 && this->user_lat >= -90 && this->user_long >= 180 && this->user_long >= -180);


        for(int i = 0; i < street.size(); i++)
        {
            this->user_distance = get_distance(user_coord[0].first, cord[i].first, user_coord[0].second, cord[i].second);

            int counter = 0;

            if(user_distance < this->radius)
            {
                // Add the locations that is within the user's radius

                // Set counter = index
                counter = i;

                // Stores the (distance, index)
                distance.push_back(std::make_pair(this->user_distance, counter));

            }
        }
    // }
    // Upper case
    // std::transform(this->address.begin(), this->address.end(), this->address.begin(), ::toupper);
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
    // std::cout << "get_distance: "<< x1 << ", " << x2 << ", " << y1 << ", " << y2 << std::endl;

    double distance;


    double converted_lat = 69;      // Convert latitude to miles
    double converted_long = 54.6;   // Convert longitude to miles

    double lat_dist = (x2-x1);
    double long_dist = (y2-y1);

    lat_dist *= converted_lat;
    long_dist *= converted_long;

    double d1 = std::pow(lat_dist, 2.0);
    double d2 = std::pow(long_dist, 2.0);

    double diff = d1 + d2;

    distance = std::sqrt(diff);

    return distance;
}

void Phone::display_data()
{
    // for(int i = 0; i < cord.size(); i++)
    // {
    //     std::cout<< street[i] << ", " << cord[i].first << ", " << cord[i].second << "\n";
    // }

    std::cout << "User Location: " << user_coord[0].first << ", " << user_coord[0].second << std::endl;
    std::cout << "Data Location: " << cord[2].first << ", " << cord[2].second << std::endl;

    // distance<mile, index>
    // unique key = index

    std::cout << "Distance vector size: " << distance.size() << std::endl;
    for(int i = 0; i < distance.size(); i++)
    {
        std::cout << "Distance: " << distance[i].first << ",    Index:" << distance[i].second << std::endl;
    }

    // std::cout << "Distance: " << get_distance(cord[1].first, cord[2].first, cord[1].second, cord[2].second) << std::endl;
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

void Phone::read_CSV_map(std::string fname2)
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
        //seperates collumns
        std::getline(ss, temp, ',');
        std::getline(ss, temp, ',');
        //gets latitude
        std::getline(ss, temp, ',');

        lat = stod(temp);
        //gets longitude
        std::getline(ss, temp, ',');
        lon = stod(temp);
        //pushes pair of lon and lat

        city_map.insert(std::pair < std::string, std::pair<double, double> > (address, std::make_pair(lat, lon)));
        //std::cout << address << "\n";
    }

    input.close();
    // for(auto &[a,b]:city_map){
    //     std::cout << a << " " << b.first << " " << b.second << "\n";
    // }
}
void Phone::write_p_queue()
{   //

    std::ofstream oFile;
    oFile.open("P_Queue.csv");
    //comparison using pythagorian theorem
    //smallest distance = top priority

    for(int i = 0; i < (distance.size()); i++){


        p_queue.push(std::make_pair(distance[i].first,
        distance[i].second));
        //check distance vector for least distance. distance, index
        //dist vector <dist, index>
        //p_q (dist, index)
        //map<city lat, lon>
        //
    }

    for(int i = 0; i < (distance.size()); i++){

        if(i < (distance.size()-1)){
            oFile << "The city " << address << " is " <<  p_queue.top().first << " miles from a resturaunt at " << street[p_queue.top().second] << "\n";
            p_queue.pop();
        }

        else{
            oFile << "The city " << address << " is " << p_queue.top().first << " miles from a resturaunt at " << street[p_queue.top().second];
            p_queue.pop();

        }

    }

    oFile.close();

}


void Phone::dataToCSV()
{
    std::ofstream outFile;
    outFile.open("Points.CSV");
    //comparison using pythagorian theorem
    //smallest distance = top priority


    for(int i = 0; i < (distance.size()); i++){
        if(i < (distance.size()-1)){
            outFile << cord[distance[i].second].first << ", " << cord[distance[i].second].second << "\n";
        }
        else{
            outFile << cord[distance[i].second].first << ", " << cord[distance[i].second].second;
        }


    }

    outFile.close();

}

int main(int argc, char ** argv)
{

    std::string name = argv[1];
    std::string name2 = argv[2];

    Phone read(name, name2);


}