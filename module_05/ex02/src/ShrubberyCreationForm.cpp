#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {
		std::cout << "ShrubberyCreationForm created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target) {
		std::cout << "ShrubberyCreationForm copied." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if(this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destroyed." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if(!this->getSignedStatus()) {
		std::cout << "Error: Form is not signed." << std::endl;
		throw AForm::FormNotSigned();
	}
	else if(executor.getGrade() > this->getGrdToExec()) {
		std::cout << "Error: Bureaucrat's grade is too low to execute the form." << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::string outputFilename = this->target + "_shrubbery";
	std::ofstream outputFile (outputFilename.c_str());
	if(!outputFile.is_open()) {
		std::cout << "Error creating file.";
		return;
	}

	outputFile << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
	outputFile << "           {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
	outputFile << "          {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
	outputFile << "       {\\{/()\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
	outputFile << "      {/{/(_)/}{\\{/){\\(_){/}/}/}/}" << std::endl;
	outputFile << "     _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
	outputFile << "    {/{/{\\{\\{(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
	outputFile << "    _{\\{/{\\{/(_)/}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
	outputFile << "   {/{/{\\{(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
	outputFile << "    {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
	outputFile << "     {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
	outputFile << "    {/{\\{\\/}{/){\\{\\{\\/}/}{\\{(/}/}\\}/}" << std::endl;
	outputFile << "     {/{\\{\\/}(_){\\{\\{(/}/}{\\(_)/}/}\\}" << std::endl;
	outputFile << "       {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
	outputFile << "        (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
	outputFile << "          {/{/{\\{\\/}{/{\\{\\{(_)/}" << std::endl;
	outputFile << "           {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
	outputFile << "            {){/ {\\/}{\\/} \\}\\}" << std::endl;
	outputFile << "              (_)  \\.-'.-/" << std::endl;
	outputFile << "          __...--- |'-.-'| --...__" << std::endl;
	outputFile << "   _...--\"   .-'  |'-.-'|  ' -.  \"\"--..__" << std::endl;
	outputFile << " -" << "\"    ' .  |'-.-'|-._| '  . .  '   " << std::endl;
	outputFile << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
	outputFile << "          ' ..     |'-_.-|   "<< std::endl;
	outputFile << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
	outputFile << "              .'   |'- .-|   '." << std::endl;
	outputFile << "  ..-'   ' .  '.   |'- .-|   .'  '  - ." << std::endl;
	outputFile << "   .-' '        '-._______.-'     '  ." << std::endl;
	outputFile << "        .      ~," << std::endl;
	outputFile << "    .       .   |\\   .    ' '-." << std::endl;
	outputFile << "    ___________/  \\____________" << std::endl;
	outputFile << "   /  Why is it, when you want \\" << std::endl;
	outputFile << "  |  something, it is so damn   |" << std::endl;
	outputFile << "  |    much work to get it?     |" << std::endl;
	outputFile << "   \\___________________________/" << std::endl;
	outputFile.close();
	std::cout << "Shrubbery created in file: " << outputFilename << std::endl;
	std::cout << "ShrubberyCreationForm executed by " << executor.getName()
          << ". Check the created file in the main directory." << std::endl;

}
//Creates a file <target>_shrubbery in the working directory and writes ASCII trees
//inside it.