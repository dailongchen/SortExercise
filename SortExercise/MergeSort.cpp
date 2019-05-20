#include "catch.hpp"

#include <queue>
#include "TestData.h"

using namespace SortExercise;

std::vector<int> merge(std::vector<int> first, std::vector<int> second) {
	std::vector<int> result;

	size_t firstIndex = 0;
	size_t secondIndex = 0;

	while (firstIndex < first.size() || secondIndex < second.size()) {
		if (firstIndex >= first.size()) {
			result.insert(result.end(), second.begin() + secondIndex, second.end());
			break;
		}

		if (secondIndex >= second.size()) {
			result.insert(result.end(), first.begin() + firstIndex, first.end());
			break;
		}

		if (first[firstIndex] < second[secondIndex]) {
			result.push_back(first[firstIndex]);
			firstIndex++;
		}
		else {
			result.push_back(second[secondIndex]);
			secondIndex++;
		}
	}

	return result;
}

std::vector<int> MergeSort(const std::vector<int>& unsorted) {
	auto sorted = unsorted;

	if (unsorted.size() <= 1) {
		return sorted;
	}

	auto middle = unsorted.size() / 2;
	auto left = std::vector<int>(unsorted.begin(), unsorted.begin() + middle);
	auto sortedLeft = MergeSort(left);

	auto right = std::vector<int>(unsorted.begin() + middle, unsorted.end());
	auto sortedRight = MergeSort(right);

	return merge(sortedLeft, sortedRight);
}

TEST_CASE("MergeSort", "[SortExercise]") {
	auto testData = GenerateTestData(10);
	auto result = MergeSort(testData.Unsorted);
	REQUIRE(result == testData.Sorted);
}