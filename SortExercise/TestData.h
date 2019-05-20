#pragma once

#include <vector>

namespace SortExercise {
	struct TestData {
		std::vector<int> Unsorted;
		std::vector<int> Sorted;
	};

	TestData GenerateTestData(int count);
}