#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(), target("DefaultTarget"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target_): AForm("ShrubberyCreationForm", 145, 137), target(target_){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target(other.target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    AForm::operator=(other);
    this->target = other.target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecution(executor);
    std::string filename = target  + "_shrubbery";
    std::ofstream file(filename);
    file << "                 .              .              ;%     ;;\n";
    file << "                   ,           ,                :;%  %;\n";
    file << "                    :         ;                   :;%;'     .,\n";
    file << "           ,.        %;     %;            ;        %;'    ,;\n";
    file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
    file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
    file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
    file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
    file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
    file << "                    `:%;.  :;bd%;          %;@%;'\n";
    file << "                      `@%:.  :;%.         ;@@%;'\n";
    file << "                        `@%.  `;@%.      ;@@%;\n";
    file << "                          `@%%. `@%%    ;@@%;\n";
    file << "                            ;@%. :@%%  %@@%;\n";
    file << "                              %@bd%%%bd%%:;\n";
    file << "                                #@%%%%%:;;\n";
    file << "                                %@@%%%::;\n";
    file << "                                %@@@%(o);\n";
    file << "                                %@@@o%;:(.,'\n";
    file << "                            `.. %@@@o%::;\n";
    file << "                               `)@@@o%::;\n";
    file << "                                %@@(o)::;\n";
    file << "                               .%@@@@%::;\n";
    file << "                               ;%@@@@%::;.\n";  
    file << "                              ;%@@@@%%:;;;.\n";
    file << "                          ...;%@@@@@%%:;;;;,..\n";
    file.close();
}
