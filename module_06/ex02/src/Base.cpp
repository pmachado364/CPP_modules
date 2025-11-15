#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

//**************** generate ****************//

struct FactoryArray {
	char className;
	Base* (*create)(); //function pointer that returns Base* and takes no parameters
};

static Base* createA() { return new A(); }
static Base* createB() { return new B(); }
static Base* createC() { return new C(); }

Base* generate(void) {
	static FactoryArray factory[] = {
		{'A', &createA},
		{'B', &createB},
		{'C', &createC}
	};
	int random = std::rand() % 3;
	std::cout << "Generated instance of class " << factory[random].className << std::endl;
	return factory[random].create();
}

//**************** Identify ****************//

struct identifier {
	char className;
	bool (*identifyFunc)(Base *); //function pointer that takes Base* and returns bool
};

static bool isA(Base* p) { return dynamic_cast<A*>(p) != NULL; } // the dynamic_cast returns nullptr if the cast fails
static bool isB(Base* p) { return dynamic_cast<B*>(p) != NULL; } // if it succeeds, it returns a valid pointer
static bool isC(Base* p) { return dynamic_cast<C*>(p) != NULL; } // so we can use this to identify the type since we only have three types

void identify(Base* p) {
	static identifier identifiers[] = {
		{'A', &isA},
		{'B', &isB},
		{'C', &isC}
	}; // array of identifiers and their corresponding functions

	for (size_t i = 0; i < 3; ++i) {
		if (identifiers[i].identifyFunc(p)) { // we call the function pointer to match it against the current element in the loop. If it returns true, we found the type
			std::cout << identifiers[i].className << std::endl;
			return;
		}
	}
	std::cout << "Unknown class" << std::endl;
}

// mt mais simples seria :
//
// void identify(Base* p) {
//     if (dynamic_cast<A*>(p))
//         std::cout << "A" << std::endl;
//     else if (dynamic_cast<B*>(p))
//         std::cout << "B" << std::endl;
//     else if (dynamic_cast<C*>(p))
//         std::cout << "C" << std::endl;
//     else
//         std::cout << "Unknown" << std::endl;
// }

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::exception& ) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::exception& ) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::exception& ) {}
	std::cout << "Unknown class" << std::endl;
}