#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Weapon {
	private:
		std::string type;
	
	public:
		Weapon();
		Weapon(const std::string& type);
		~Weapon();

		const std::string& getType() const;
		void setType(const std::string& newType);

};

#endif