#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

void insertSortedDeque(std::deque<int> &sortedList, int number);
void insertSortedVector(std::vector<int> &sortedList, int number);
std::vector<std::deque<int> > createPairsDeque(std::deque<int> &numbers);
void fordJohnsonSortVector(std::vector<int> &numbers);
void fordJohnsonSortDeque(std::deque<int> &numbers);
void printSequence(const std::string &label, const std::vector<int> &numbers);
void printSequence(const std::string &label, const std::deque<int> &numbers);
