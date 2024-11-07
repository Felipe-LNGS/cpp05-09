#include "PmergeMe.hpp"

v0oid insertSortedVector(std::vector<int> &sortedList, int number) {
    std::vector<int>::iterator position = std::lower_bound(sortedList.begin(), sortedList.end(), number);
    sortedList.insert(position, number);
}

void insertSortedDeque(std::deque<int> &sortedList, int number) {
    std::deque<int>::iterator position = std::lower_bound(sortedList.begin(), sortedList.end(), number);
    sortedList.insert(position, number);
}

std::vector<std::vector<int> > createPairsVector(std::vector<int> &numbers) {
    std::vector<std::vector<int> > pairs;
    int totalNumbers = numbers.size();
    int i = 0;

    while (i < totalNumbers) {
        if (i + 1 < totalNumbers) {
            if (numbers[i] > numbers[i + 1]) {
                std::swap(numbers[i], numbers[i + 1]);
            }
            std::vector<int> pair1;
            pair1.push_back(numbers[i]);
            pairs.push_back(pair1);

            std::vector<int> pair2;
            pair2.push_back(numbers[i + 1]);
            pairs.push_back(pair2);

            i += 2;
        } else {
          
            std::vector<int> pair1;
            pair1.push_back(numbers[i]);
            pairs.push_back(pair1);
            ++i;
        }
    }

    return pairs;
}

std::vector<std::deque<int> > createPairsDeque(std::deque<int> &numbers) {
    std::vector<std::deque<int> > pairs;
    int totalNumbers = numbers.size();
    int i = 0;

    while (i < totalNumbers) {
        if (i + 1 < totalNumbers) {
            if (numbers[i] > numbers[i + 1]) {
                std::swap(numbers[i], numbers[i + 1]);
            }
            std::deque<int> pair1;
            pair1.push_back(numbers[i]);
            pairs.push_back(pair1);

            std::deque<int> pair2;
            pair2.push_back(numbers[i + 1]);
            pairs.push_back(pair2);

            i += 2; 
        } else {
            std::deque<int> pair1;
            pair1.push_back(numbers[i]);
            pairs.push_back(pair1); 
            ++i;
        }
    }

    return pairs;
}

void fordJohnsonSortVector(std::vector<int> &numbers) {
    std::vector<std::vector<int> > pairs = createPairsVector(numbers);
    std::vector<int> sortedList;

    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = 0; j < pairs[i].size(); ++j) {
            insertSortedVector(sortedList, pairs[i][j]);
        }
    }

    for (size_t i = 0; i < sortedList.size(); ++i) {
        numbers[i] = sortedList[i];
    }
}

void fordJohnsonSortDeque(std::deque<int> &numbers) {
    std::vector<std::deque<int> > pairs = createPairsDeque(numbers);
    std::deque<int> sortedList;

    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = 0; j < pairs[i].size(); ++j) {
            insertSortedDeque(sortedList, pairs[i][j]);
        }
    }

    for (size_t i = 0; i < sortedList.size(); ++i) {
        numbers[i] = sortedList[i];
    }
}

void printSequence(const std::string &label, const std::vector<int> &numbers) {
    std::cout << label;
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void printSequence(const std::string &label, const std::deque<int> &numbers) {
    std::cout << label;
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}