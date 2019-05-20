#include "catch.hpp"

#include <queue>

#include "TestData.h"

using namespace SortExercise;

std::vector<int> QuickSort(const std::vector<int>& unsorted) {
	auto sorted = unsorted;

	std::queue<std::pair<int, int>> ranges;
	ranges.push(std::make_pair(0, sorted.size() - 1));

	bool forwardDirection = false;
	while (!ranges.empty()) {
		auto from = ranges.front().first;
		auto to = ranges.front().second;
		ranges.pop();

		auto i = from;
		auto j = to;
		while (i < j) {
			if (sorted[i] > sorted[j]) {
				std::swap(sorted[i], sorted[j]);
				forwardDirection = !forwardDirection;
			}

			if (forwardDirection) {
				i++;
			}
			else {
				j--;
			}
		}

		if (i - 1 > from) {
			ranges.push(std::make_pair(from, i - 1));
		}
		if (j + 1 < to) {
			ranges.push(std::make_pair(j + 1, to));
		}
	}

	return sorted;
}

TEST_CASE("QuickSort", "[SortExercise]") {
	auto testData = GenerateTestData(10);
	auto result = QuickSort(testData.Unsorted);
	REQUIRE(result == testData.Sorted);
}