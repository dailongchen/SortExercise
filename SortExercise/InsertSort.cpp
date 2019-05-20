#include "catch.hpp"

#include "TestData.h"

using namespace SortExercise;

std::vector<int> InsertSort(const std::vector<int>& unsorted) {
	auto sorted = unsorted;

	for (size_t i = 1; i < sorted.size(); i++) {
		for (size_t j = 0; j < i; j++) {
			if (sorted[i] < sorted[j]) {
				auto iter = sorted.begin() + i;
				auto value = *iter;
				sorted.erase(iter);

				auto insertAt = sorted.begin() + j;
				sorted.insert(insertAt, value);

				break;
			}
		}
	}
	
	return sorted;
}

TEST_CASE("InsertSort", "[SortExercise]") {
	auto testData = GenerateTestData(10);
	auto result = InsertSort(testData.Unsorted);
	REQUIRE(result == testData.Sorted);
}