#include "vector.h"
#include <iostream>
#include <vector>

using namespace ALib;

int main()
{
    Vector<std::string> vec;

    for (int i = 0; i < 10; i++) 
    {
        vec.pushBack("1411");
        std::cout << vec[i];
    }
    std::cout << std::endl << vec[3] << std::endl;
    vec[3] = "51511";
    std::cout << std::endl << vec[3] << std::endl;
    system("pause");

    std::vector<int> vec2;

    return 0;
}
