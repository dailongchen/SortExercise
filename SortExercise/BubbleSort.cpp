#include "catch.hpp"

#include "TestData.h"

using namespace SortExercise;

std::vector<int> BubbleSort(const std::vector<int>& unsorted) {
	auto sorted = unsorted;

	for (int to = sorted.size() - 1; to > 0; to--) {
		bool changed = false;
		for (int from = 0; from < to; from++) {
			if (sorted[from] > sorted[from + 1]) {
				std::swap(sorted[from], sorted[from + 1]);
				changed = true;
			}
		}

		if (!changed) {
			break;
		}
	}

	return sorted;
}

TEST_CASE("BubbleSort", "[SortExercise]") {
	auto testData = GenerateTestData(10);
	auto result = BubbleSort(testData.Unsorted);
	REQUIRE(result == testData.Sorted);
}