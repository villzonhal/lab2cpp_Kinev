#include "functions.h"

#include <algorithm>
#include <iterator>
#include <numeric>
#include <set>

template <typename Container>
void DoubleFirstMiddleLast(Container& container) {
    typename Container::iterator middle = container.begin();
    std::advance(middle, static_cast<int>(container.size()) / 2);
    *container.begin() *= 2;
    *middle *= 2;
    *std::prev(container.end()) *= 2;
}


template void DoubleFirstMiddleLast<std::vector<int>>(std::vector<int>&);
template void DoubleFirstMiddleLast<std::deque<int>>(std::deque<int>&);
template void DoubleFirstMiddleLast<std::list<int>>(std::list<int>&);

void AppendReversedFirstThird(std::list<int>& values) {
    int third = static_cast<int>(values.size()) / 3;
    std::list<int>::iterator third_end = values.begin();
    std::advance(third_end, third);
    std::list<int>::reverse_iterator first(third_end);
    std::vector<int> reversed(first, values.rend());
    values.insert(values.end(), reversed.begin(), reversed.end());
}

void EraseEvenPositionsInFirstHalf(std::deque<int>& values) {
    int quarter = static_cast<int>(values.size()) / 4;
    std::deque<int>::iterator it = values.begin();
    for (int i = 0; i < quarter; ++i) {
        it = values.erase(++it);
    }
}

void WriteReplacedNumbers(std::istream& input, std::ostream& output) {
    std::replace_copy(std::istream_iterator<int>(input),
        std::istream_iterator<int>(),
        std::ostream_iterator<int>(output, "  "), 0, 10);
}

bool EraseLastZeroRun(std::vector<int>& values, int k) {
    std::vector<int>::reverse_iterator run =
        std::search_n(values.rbegin(), values.rend(), k, 0);
    if (run == values.rend()) {
        return false;
    }
    values.erase((run + k).base(), run.base());
    return true;
}

void ReverseFirstHalf(std::list<int>& values) {
    int quarter = static_cast<int>(values.size()) / 4;
    std::list<int>::iterator quarter_end = values.begin();
    std::advance(quarter_end, quarter);
    std::list<int>::iterator middle = quarter_end;
    std::advance(middle, quarter);
    std::list<int>::reverse_iterator from_middle(middle);
    std::swap_ranges(values.begin(), quarter_end, from_middle);
}

void ReverseSecondHalf(std::list<int>& values) {
    std::list<int>::iterator middle = values.begin();
    std::advance(middle, static_cast<int>(values.size()) / 2);
    std::reverse(middle, values.end());
}

void CountEvenAndOdd(std::list<int> values, int& even, int& odd) {
    std::list<int>::iterator border = std::partition(
        values.begin(), values.end(), [](int x) { return x % 2 == 0; });
    even = static_cast<int>(std::distance(values.begin(), border));
    odd = static_cast<int>(std::distance(border, values.end()));
}

std::vector<double> AdjacentMeans(const std::list<int>& values) {
    std::vector<double> means;
    std::adjacent_difference(
        values.begin(), values.end(), std::back_inserter(means),
        [](int current, int previous) {
            return (static_cast<double>(current) + previous) / 2;
        });
    if (!means.empty()) {
        means.erase(means.begin());
    }
    return means;
}

int CountVectorsContaining(const std::vector<int>& v0,
    const std::vector<std::vector<int>>& vectors) {
    std::multiset<int> required(v0.begin(), v0.end());
    int count = 0;
    for (const std::vector<int>& vi : vectors) {
        std::multiset<int> current(vi.begin(), vi.end());
        if (std::includes(current.begin(), current.end(),
            required.begin(), required.end())) {
            ++count;
        }
    }
    return count;
}

std::multimap<char, std::string> GroupByLastLetter(
    const std::vector<std::string>& words) {
    std::vector<std::string> reversed(words.rbegin(), words.rend());
    std::multimap<char, std::string> groups;
    for (const std::string& word : reversed) {
        groups.insert(std::make_pair(word.back(), word));
    }
    return groups;
}
