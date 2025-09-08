#include "Replace.hpp"

ReplaceString::ReplaceString(const std::string& f, const std::string& s1, const std::string& s2) {
	this -> filename = f;
	this -> s1 = s1;
	this -> s2 = s2;
}

ReplaceString::~ReplaceString() {
	// Destructor implementation if needed
}

void ReplaceString::replaceInFile () {

	if (this -> s1.empty()) {
			std::cout << " Error : s1 cannot be empty." << std::endl;
			return;
	}

	std::ifstream inputFile(this -> filename.c_str()); // Abrir o ficheiro de input. E usar c_str() porque o constructor do ifstream nao aceita std::string
	if(!inputFile.is_open()) {
		std::cout << "Error: Could not open file " << this -> filename << std::endl;
		return;
	} // Verificar se o ficheiro abriu

	std::string outputFilename = this -> filename + ".replace"; // Variavel que vai guardar o nome + ".replace"
	std::ofstream outputFile (outputFilename.c_str()); // Criar o ficheiro de output
	if(!outputFile.is_open()) {
		std::cout << "Error: Could not create file " << outputFilename << std::endl;
		inputFile.close();
		return;
	}

	std::string line;
	while (std::getline(inputFile, line)) { // Ler o ficheiro linha a linha
		std::string match;
		std::size_t start = 0;

		while(true) {
			std::size_t pos = line.find(this -> s1, start);

			 std::cout << "Looking for [" << this->s1
              		<< "] in line starting at " << start
              		<< " → found at: " << pos << std::endl;

			if (pos == std::string::npos) {
				match += line.substr(start); // Adicionar o resto da linha se nao houver mais ocorrencias
				break;
			}
			match += line.substr(start, pos - start); // Adicionar a parte da linha antes da ocorrencia
			match += this -> s2; // Adicionar s2 no lugar de s1
			start = pos + this -> s1.length(); // Avancar o indice start para continuar a procurar
		}
		// for (int i = 0; i < line.length(); i++) {
		// 	if(line.substr(i, this -> s1.length()) == this -> s1) {
		// 		match += this -> s2;
		// 		i += this -> s1.length() - 1; // Avancar o indice i para evitar sobreposicoes
		// 	} else
		// 		match += line[i];
		// }
		outputFile << match << std::endl; // Escrever a linha modificada no ficheiro de output
	}
}