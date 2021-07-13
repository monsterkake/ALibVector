#include "vector.h"
#include <iostream>
#include <vector>

using namespace ALib;

int main()
{
    
    
    /*
    for(int i = 0; i< 10;i++){
       
        vec.pushFront(i);
    }
    for (int i = 0; i < vec.size(); i++) {

        std::cout << vec[i] << " " << std::endl;
    }
    for (int i = vec.size()-1; i >=0 ; i--) {

        std::cout << vec[i] << " " << std::endl;
    }
    for (int i = vec.size() - 1; i >= 0; i--) {

        vec.popBack();
    }
    for (int i = 0; i < 10; i++) {

        vec.pushBack(i);
    }
    for (int i = vec.size() - 1; i >= 0; i--) {

        std::cout << vec[i] << " " << std::endl;
    }
    
    
    while (true) 
    {
        
        vec.pushBack(1);
        vec.popBack();
        std::cout << vec[0] << " " << std::endl;
        //vec.pushFront(1);
        //vec.popBack();
    }
    */
    Vector<int> vec;
    for (int i = 0; i < 10; i++) {

        vec.pushFront(i);
    }
    vec[0] = 0;
    vec[1] = 0;
    vec[2] = 0;
    vec[3] = 0;

    for (int i = vec.size() - 1; i >= 0; i--) {

        std::cout << vec[i] << " " << std::endl;
    }

    system("pause");


    return 0;
}
