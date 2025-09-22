#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Brain {
	private:
		static const int nIdeas = 100;
		std::string ideas[nIdeas];
	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();

		Brain& operator=(const Brain& copy);

		const std::string& getIdea(int index) const;
		void setIdea(int index, const std::string& idea);
		void addRandomThoughts();
};

#endif