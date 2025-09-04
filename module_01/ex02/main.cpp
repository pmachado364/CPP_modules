#include <iostream>
#include <string>

int main() {
	std::string sentence = "HI THIS IS BRAIN";
	std::string* stringPTR = &sentence;
	std::string& stringREF = sentence;

	std::cout << "Memory address of the string: " << &sentence << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string is : " << sentence << std::endl;
	std::cout << "The value pointed to by stringPTR is : " << *stringPTR << std::endl;
	std::cout << "The value referenced by stringREF is : " << stringREF << std::endl;
	return 0;
}