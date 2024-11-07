#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc <= 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        std::cerr << "Usage: ./PmergeMe [numbers to sort]" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> vectorNumbers;
    std::deque<int> dequeNumbers;
    for (int i = 1; i < argc; ++i) {
        int number = std::atoi(argv[i]);
        if (number <= 0) {
            std::cerr << "Error: Only positive integers are allowed." << std::endl;
            return EXIT_FAILURE;
        }
        vectorNumbers.push_back(number);
        dequeNumbers.push_back(number);
    }

    printSequence("Before sorting: ", vectorNumbers);

    // Mesure du temps de tri pour le vecteur
    clock_t start, end;
    start = clock();
    fordJohnsonSortVector(vectorNumbers);
    end = clock();
    double timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << std::endl;
    // Mesure du temps de tri pour la deque
    start = clock();
    fordJohnsonSortDeque(dequeNumbers);
    end = clock();
    double timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    printSequence("After sorting (vector): ", vectorNumbers);
    std::cout << std::endl;
    printSequence("After sorting (deque):  ", dequeNumbers);

    std::cout << "Time to process " << vectorNumbers.size() << " elements with std::vector: " << timeVector << " ms" << std::endl;
    std::cout << "Time to process " << dequeNumbers.size() << " elements with std::deque:  " << timeDeque << " ms" << std::endl;

    return EXIT_SUCCESS;
}