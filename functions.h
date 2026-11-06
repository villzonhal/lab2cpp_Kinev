#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <deque>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <istream>
#include <ostream>

template <typename Container>
void DoubleFirstMiddleLast(Container& container);

void AppendReversedFirstThird(std::list<int>& values);
void EraseEvenPositionsInFirstHalf(std::deque<int>& values);
void WriteReplacedNumbers(std::istream& input, std::ostream& output);
bool EraseLastZeroRun(std::vector<int>& values, int k);
void ReverseFirstHalf(std::list<int>& values);
void ReverseSecondHalf(std::list<int>& values);
void CountEvenAndOdd(std::list<int> values, int& even, int& odd);
std::vector<double> AdjacentMeans(const std::list<int>& values);
int CountVectorsContaining(const std::vector<int>& v0,
    const std::vector<std::vector<int>>& vectors);
std::multimap<char, std::string> GroupByLastLetter(
    const std::vector<std::string>& words);

#endif
