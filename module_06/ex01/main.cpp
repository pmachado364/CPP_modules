#include "Serialize.hpp"

int main() {
	Data Earth = {"Earth", 1, 365.25, 'N', 149.6f};

	std::cout << "\n*****[ Manual Memory Inspection ]*****" << std::endl;
	std::cout << "Note: Using reinterpret_cast and byte-level pointer arithmetic." << std::endl;
	std::cout << "(This is not reliable in production due to compiler padding/alignment.)\n" << std::endl;

	std::cout << "Data Earth Address: " << &Earth << std::endl;
	std::cout << "Planet (std::string) internal pointer: " << reinterpret_cast<void*>(*reinterpret_cast<uintptr_t*>((char*)&Earth))<< std::endl;
	std::cout << "Moons (int): " << *reinterpret_cast<int*>((char*)&Earth + sizeof(std::string)) << std::endl;
	// Skipping the string (planet) and reading the int moons field
	std::cout << "Orbital Period (int): " << *reinterpret_cast<int*>((char*)&Earth + sizeof(std::string) + sizeof(int)) << std::endl;
	// Skipping string + int to reach orbitalPeriod
	std::cout << "Atmosphere Type (double): " << *reinterpret_cast<double*>((char*)&Earth + sizeof(std::string) + sizeof(int) + sizeof(double)) << std::endl;
	// Skipping string + int + double to reach atmosphericComposition

	std::cout << "\nImportant notes:\n";
	std::cout << "  • We cast to (char*) so we can move through the struct byte by byte.\n";
	std::cout << "  • Then we add sizeof(...) to skip specific fields.\n";
	std::cout << "  • Finally, we reinterpret_cast back to the target type and dereference.\n";

	std::cout << "\n*****[ After Serialize ]*****" << std::endl;
	uintptr_t serialized = Serializer::serialize(&Earth);
	std::cout << "Serialized Data Address (uintptr_t): " << serialized << std::endl;
	std::cout << "Planet Address after Serialize: " << reinterpret_cast<void*>(serialized) << std::endl;
	std::cout << "Moons (int) after Serialize: " << *reinterpret_cast<int*>((char*)reinterpret_cast<Data*>(serialized) + sizeof(std::string)) << std::endl;

	std::cout << "\n*****[ Deserialized Data ]*****" << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data Address (uintptr_t): " << reinterpret_cast<uintptr_t>(deserialized) << std::endl;
	std::cout << "Planet Address after Deserialize: " << reinterpret_cast<void*>(deserialized) << std::endl;
	std::cout << "Moons (int) after Deserialize: " << *reinterpret_cast<int*>((char*)deserialized + sizeof(std::string)) << std::endl;
	
	std::cout << "\nDeserialized address matches original: "
			  << std::boolalpha << (deserialized == &Earth) << std::endl;

	return 0;
}

