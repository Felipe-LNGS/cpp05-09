#include "Base.hpp"

	Base::Base(){}
	Base::~Base(){}

	Base *Base::generate(void){
	std::srand(static_cast<unsigned int>(std::time(0)));
	int randomNumber = std::rand() % 3 + 1;

	  switch (randomNumber) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
		}

	void Base::identify(Base* p) {
    std::cout << BOLD + PURP +"WITH POINTER" +RESET << std::endl;

    if (dynamic_cast<A*>(p)) {
        std::cout << GRNN +"Type of base object pointed :" +RESET<< " A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << GRNN +"Type of base object pointed :" +RESET<< " B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << GRNN +"Type of base object pointed :" +RESET<< " C" << std::endl;
    } else {
        std::cout << REDD +"Unknown type" +RESET << std::endl;
    }
}

void Base::identify(Base& p) {
    std::cout << BOLD + PURP +"WITH REFERENCE" +RESET << std::endl;
    
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << GRNN +"Type of base object pointed :" +RESET<< " A" << std::endl;
		(void)a;
    } catch (std::bad_cast& e) {
        std::cout << REDD +"Is not type : " +RESET<< " A" << std::endl;
    }

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << GRNN +"Type of base object pointed :" +RESET<< " B" << std::endl;
		(void)b;
    } catch (std::bad_cast& e) {
        std::cout << REDD +"Is not type : " +RESET<< " B" << std::endl;
    }

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << GRNN +"Type of base object pointed :" +RESET<< " C" << std::endl;
		(void)c;
    } catch (std::bad_cast& e) {
        std::cout << REDD +"Is not type : " +RESET<< " C" << std::endl;
    }
}
