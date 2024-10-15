#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
/*****************BASIC*****************/
       
   
    try{
         Form workPermit("Work permit", 3, 4);
        Bureaucrat eugene("Eugene", 3);
        std::cout << eugene << std::endl;
        std::cout << workPermit << std::endl;
        eugene.signForm(workPermit);
    }
    catch (std::exception & e)
    {
        std::cout <<REDD+ e.what() +RESET<< std::endl << std::endl;
    }
/*****************GRADE TO HIGH*****************/
    try{
        Bureaucrat eugene("Eugene", 1);
        std::cout << eugene << std::endl;
        Form workPermit("Work permit", 0, 0);
        std::cout << workPermit << std::endl;
        eugene.signForm(workPermit);

    }
    catch (std::exception & e)
    {
        std::cout << REDD << e.what() << RESET << std::endl<< std::endl;
    }
/*****************GRADE TO LOW*****************/
    try{
        Bureaucrat eugene("Eugene", 120);
        std::cout << eugene << std::endl;
        Form workPermit("Work permit", 151, 151);
        std::cout << workPermit << std::endl;
        eugene.signForm(workPermit);

    }
    catch (std::exception & e)
    {
        std::cout << REDD<< e.what() << RESET << std::endl<< std::endl;
    }
/*****************SIGN TO LOW*****************/
    try{
        Bureaucrat eugene("Eugene", 120);
        std::cout << eugene << std::endl;
        Form workPermit("Work permit", 1, 3);
        std::cout << workPermit << std::endl;
        eugene.signForm(workPermit);

    }
    catch (std::exception & e)
    {
        std::cout << REDD<< e.what() << RESET << std::endl<< std::endl;
    }
}
