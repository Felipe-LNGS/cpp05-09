#include "Span.hpp"

int main()
{
srand(time(0));
/**********MANDATORY*********/
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

/**********TEST 10K*********/
// Span sp = Span(n10K);

// try{

// std::vector<int> numbers = randomNumber(n10K);
// sp.addNumbers(numbers.begin(), numbers.end());
// std::cout << std::endl;
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// }
// catch (std::exception &e)
// {
//     std::cout << std::endl;
//     std::cerr << e.what() << std::endl;
// }

/**********VEC EMPTY*********/
// Span sp = Span(n10K);

// try{

// std::vector<int> numbers = randomNumber(0);
// sp.addNumbers(numbers.begin(), numbers.end());

// std::cout << std::endl;
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// }
// catch (std::exception &e)
// {
//     std::cout << std::endl;
//     std::cerr << e.what() << std::endl;
// }

/**********VEC FULL*********/
// Span sp = Span(n10K);

// try{

// std::vector<int> numbers = randomNumber(n10K);
// sp.addNumbers(numbers.begin(), numbers.end());
// sp.addNumbers(numbers.begin(), numbers.end());

// std::cout << std::endl;
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// }
// catch (std::exception &e)
// {
//     std::cout << std::endl;
//     std::cerr << e.what() << std::endl;
// }


return 0;
}