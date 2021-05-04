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

int main(int argc, char ** argv)
{

    std::string ad1 = "2059 w street";
    std::string ad2 = "2039 w street";
    std::string ad3 = "2059 w street";

    int res;
    // res = ad1.compare(ad2);

    // if(res == 0)
    // {
    //     std::cout << "Same address!" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Not same address!" << std::endl;
    // }

    // res = ad1.compare(ad3);
    // if(res == 0)
    // {
    //     std::cout << "Same address!" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Not same address!" << std::endl;
    // }

    std::string user1;

    std::cout << "Enter address: ";
    std::getline(std::cin, user1);

    std::cout << user1;
    res = ad1.compare(user1);
    if(res == 0)
    {
        std::cout << "Same address!" << std::endl;
    }
    else
    {
        std::cout << "Not same address!" << std::endl;
    }

}