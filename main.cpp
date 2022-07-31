#include <iostream> 
#include "quarternion.h"

int main()
{
    int k = 5;
    Quarternion<double> a = {1,2,3,4};
    Quarternion<double> b = {4,3,2,1};
    Quarternion<double> c = a + b;

    std::cout << "Quarternion \"a\" has values: " << a << std::endl;
    std::cout << "Quarternion \"b\" has values: " << b << std::endl;
    std::cout << "Quarternion \"c\" has values: " << c << std::endl;

    return 0;
}