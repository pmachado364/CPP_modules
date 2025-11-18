// #include "Array.hpp"

// #include <cstdlib>
// #include <ctime>
// #include <string>
// #include <sstream>

// std::string to_string98(int n)
// {
// 	std::ostringstream ss;
// 	ss << n;
// 	return ss.str();
// }

// int main() {
// 	srand(time(NULL));
// 	Array<int> array1(4);
// 	for(unsigned int i = 0; i < array1.size(); i++) {
// 		array1[i] = rand() % 100;
// 		std::cout << "array1[" << i << "] = " << array1[i] << std::endl;
// 	};

// 	Array<int> array2(3);
// 	for(unsigned int i = 0; i < array2.size(); i++) {
// 		array2[i] = rand() % 100;
// 		std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
// 	};

// 	array2 = array1;
// 	std::cout << "After assignment, array2 contents:" << std::endl;
// 	for(unsigned int i = 0; i < array2.size(); i++) {
// 		std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
// 	};

// 	Array<std::string> array_std(3);
// 	for(unsigned int i = 0; i < array_std.size(); i++) {
// 		array_std[i] = "String_" + to_string98(i);
// 		std::cout << "array_std[" << i << "] = " << array_std[i] << std::endl;
// 	};

// 	Array<std::string> array_std2(10);
// 	for(unsigned int i = 0; i < array_std2.size(); i++) {
// 		array_std2[i] = "Init_String_" + to_string98(i);
// 		std::cout << "array_std2[" << i << "] = " << array_std2[i] << std::endl;
// 	};
// 	array_std2 = array_std;
// 	array_std2 [1] = "Modified_String";
// 	for(unsigned int i = 0; i < array_std2.size(); i++) {
// 		std::cout << "array_std2[" << i << "] = " << array_std2[i] << std::endl;
// 	};
		
// 	return 0;
// }

#include <iostream>
#include <Array.hpp>
#include <cstdlib>   // for srand, rand
#include <ctime>     // for time

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}