#include "TestData.h"

#include <algorithm>
#include <random>

namespace SortExercise {
	TestData GenerateTestData(int count) {
		TestData testData;

		std::random_device rd;
		std::uniform_int_distribution<int> dist(0, count * 2);

		for (int n = 0; n < 10; ++n) {
			testData.Unsorted.push_back(dist(rd));
		}

		testData.Sorted = testData.Unsorted;
		std::sort(testData.Sorted.begin(), testData.Sorted.end());

		return testData;
	}
}
