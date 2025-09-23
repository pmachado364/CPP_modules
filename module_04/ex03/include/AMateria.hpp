#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Character.hpp"
#include "ICharacter.hpp"
#include <string>

class AMateria {
	protected:
		std::string type;
	public:
		AMateria(); //default constructor
		AMateria(const AMateria &other); //copy constructor
		AMateria &operator=(const AMateria &other); //copy assignment operator
		virtual ~AMateria(); //destructor

		AMateria(std::string const & type); //parameterized constructor
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0; //pure virtual function 
		virtual void use(ICharacter& target); //uses the materia on the target. What is materia? Not sure yet.
};

#endif