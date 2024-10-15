#include "Bureaucrat.hpp"

int main() {
/*****************BASIC*****************/
    try{
        Bureaucrat eugene("Eugene", 1);
        std::cout << eugene << std::endl;
        eugene.decrementGrade();
        std::cout << eugene << std::endl<< std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
/*****************GRADE TO HIGH*****************/
    try{
        Bureaucrat eugene("Eugene", 0);
        std::cout << eugene << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << REDD << e.what() << RESET << std::endl<< std::endl;
    }
/*****************GRADE TO LOW*****************/
    try{
        Bureaucrat eugene("Eugene", 151);
        std::cout << eugene << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << TURQ << e.what() << RESET << std::endl<< std::endl;
    }
/*****************DECREMENTE TO LOW*****************/
    try{
        Bureaucrat eugene("Eugene", 150);
        std::cout << eugene << std::endl;
        eugene.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << TURQ << e.what() << RESET << std::endl<< std::endl;
    }
/*****************INCREMENTE TO HIGH*****************/
    try{
        Bureaucrat eugene("Eugene", 1);
        std::cout << eugene << std::endl;
        eugene.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << REDD << e.what() << RESET << std::endl;
    }
    
}
