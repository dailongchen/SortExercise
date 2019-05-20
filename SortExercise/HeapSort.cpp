#include "catch.hpp"

#include <algorithm>
#include <queue>
#include "TestData.h"

using namespace SortExercise;

// Adjust to maxHeap using insert method
void buildHeapByInsert(std::vector<int>& data) {
	for (size_t i = 1; i < data.size(); i++) {
		int current = i;
		while (current >= 1) {
			int parent = (current - 1) / 2;
			if (data[parent] >= data[current]) {
				break;
			}

			std::swap(data[parent], data[current]);
			current = parent;
		}
	}
}

// Adjust to maxHeap using heapify method
int heapify(std::vector<int>& data, int count, int i) {
	auto leftChild = i * 2 + 1;
	auto rightChild = i * 2 + 2;

	auto largest = i;

	if (leftChild < count) {
		if (data[largest] < data[leftChild]) {
			largest = leftChild;
		}
	}

	if (rightChild < count) {
		if (data[largest] < data[rightChild]) {
			largest = rightChild;
		}
	}

	if (largest != i) {
		std::swap(data[i], data[largest]);
		return largest;
	}

	return -1;
}

void buildHeapByHeapify(std::vector<int>& data) {
	std::queue<int> toHeapify;

	for (int i = data.size() / 2 - 1; i >= 0; i--) {
		toHeapify.push(i);
	}

	while (!toHeapify.empty()) {
		auto i = toHeapify.front();
		toHeapify.pop();

		auto adjusted = heapify(data, data.size(), i);

		if (adjusted > 0) {
			toHeapify.push(adjusted);
		}
	}
}

void sortHeap(std::vector<int>& heap) {
	for (int i = heap.size() - 1; i >= 0; i--) {
		std::swap(heap[0], heap[i]);

		int adjusted = 0;
		
		while (adjusted >= 0) {
			adjusted = heapify(heap, i, adjusted);
		}
	}
}

std::vector<int> HeapSort_1(const std::vector<int>& unsorted) {
	auto heap = unsorted;

	buildHeapByHeapify(heap);
	sortHeap(heap);

	return heap;
}

std::vector<int> HeapSort_2(const std::vector<int>& unsorted) {
	auto heap = unsorted;

	buildHeapByInsert(heap);
	sortHeap(heap);

	return heap;
}

TEST_CASE("HeapSort", "[SortExercise]") {
	auto testData = GenerateTestData(10);

	auto result = HeapSort_1(testData.Unsorted);
	REQUIRE(result == testData.Sorted);

	result = HeapSort_2(testData.Unsorted);
	REQUIRE(result == testData.Sorted);
}