#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include"ShrubberyCreationForm.hpp" 
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
int main() {
/*****************BASIC*****************/
       
   
    // try{
    //     RobotomyRequestForm robot("eugene");
    //     ShrubberyCreationForm file("home");
    //     PresidentialPardonForm pardon("eugene");
    //     Bureaucrat eugene("Eugene", 1 );
    //     std::cout << eugene << std::endl;
    //     std::cout << pardon << std::endl;
    //     eugene.executeForm(pardon);
    //     std::cout << robot << std::endl;
    //     eugene.executeForm(robot);
    //     std::cout << file << std::endl;
    //     eugene.executeForm(file);
    // }
    // catch (std::exception & e)
    // {
    //     std::cout <<REDD+ e.what() +RESET<< std::endl << std::endl;
    // }
 
// // /*****************SIGN TO LOW*****************/
    // try{
    //     RobotomyRequestForm robot("eugene");
    //     ShrubberyCreationForm file("home");
    //     PresidentialPardonForm pardon("eugene");
    //     Bureaucrat eugene("Eugene", 146 );
    //     std::cout << eugene << std::endl;
    //     std::cout << pardon << std::endl;
    //     eugene.executeForm(pardon);
    //     std::cout << robot << std::endl;
    //     eugene.executeForm(robot);
    //     std::cout << file << std::endl;
    //     eugene.executeForm(file);
    // }
    // catch (std::exception & e)
    // {
    //     std::cout <<REDD+ e.what() +RESET<< std::endl << std::endl;
    // }
 
// // /*****************EXEC TO LOW*****************/
    try{
        RobotomyRequestForm robot("eugene");
        ShrubberyCreationForm file("home");
        PresidentialPardonForm pardon("eugene");
        Bureaucrat eugene("Eugene", 136 );
        std::cout << eugene << std::endl;
        std::cout << pardon << std::endl;
        eugene.executeForm(pardon);
        std::cout << robot << std::endl;
        eugene.executeForm(robot);
        std::cout << file << std::endl;
        eugene.executeForm(file);
    }
    catch (std::exception & e)
    {
        std::cout <<REDD+ e.what() +RESET<< std::endl << std::endl;
    }
 
}
