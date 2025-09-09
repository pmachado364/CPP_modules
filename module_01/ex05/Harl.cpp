#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Do you want to say something to Harl before creating him?" << std::endl;
	std::string message;
	std::getline(std::cin, message);
	if(!message.empty()){
		std::cout << "> " << message << "?? Pathetic...." << std::endl;
	}
	else
		std::cout << "> Silence is the best answer to a fool..." << std::endl;
	std::cout << "** Pleasant Harl was created **" << std::endl;
}

Harl::~Harl () {
	std::cout << "** Pleasant Harl was destroyed **" << std::endl;
}

void Harl::debug (void) {
	std::cout << "# DEBUG #" << std::endl
			  << "> I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do! " << std::endl;
}

void Harl::info () {
	std::cout << "# INFO #" << std::endl
			  << "> I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning () {
	std::cout << "# WARNING #" << std::endl
			  << "> I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here just last month." << std::endl;
}

void Harl::error () {
	std::cout << "# ERROR #" << std::endl
			  << "> This is unacceptable! I want to speak to the manager now!" << std::endl;
}

void Harl::complain( std::string level ) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*pointers[4]) (void)= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*pointers[i])();
			return;
		}
	}
	std::cout << "> Harl: Maybe try DEBUG, INFO, WARNING or ERROR next time..." << std::endl;
}
