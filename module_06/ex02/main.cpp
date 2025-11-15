#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class toCauseError : public Base {};

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	for (int i = 0; i < 3; ++i) {
		Base* obj = generate();
		identify(obj);
		delete obj;
	}

	Base* errorObj = new toCauseError();
	identify(errorObj);
	identify(*errorObj);
	delete errorObj;

	Base* correctObj = generate();
	identify(correctObj);
	identify(*correctObj);
	delete correctObj;
	
	return 0;
}