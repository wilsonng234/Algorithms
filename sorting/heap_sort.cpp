#include <iostream>
#include <vector>
#include <cassert>

#include "../data_structures/priority_queue.hpp"
#include "../data_structures/binary_heap.cpp"

namespace sorting
{
    namespace heap_sort
    {
        void HeapSort(std::vector<int> &arr)
        {
            data_structures::priority_queue::PriorityQueue<int> *minHeap = new data_structures::binary_heap::MinHeap<int>();

            for (int i = 0; i < arr.size(); i++)
                minHeap->Insert(arr[i]);

            for (int i = 0; i < arr.size(); i++)
                arr[i] = minHeap->ExtractMin();

            delete minHeap;
        }

        void Test()
        {
            std::vector<int> arr = {5, -2, 4, -6, 1, 3};
            HeapSort(arr);
            assert(arr == std::vector<int>({-6, -2, 1, 3, 4, 5}));

            arr = {1};
            HeapSort(arr);
            assert(arr == std::vector<int>({1}));

            arr = {20, 3};
            HeapSort(arr);
            assert(arr == std::vector<int>({3, 20}));

            arr = {3, 20, 7};
            HeapSort(arr);
            assert(arr == std::vector<int>({3, 7, 20}));

            arr = {3, 20, 7, 1};
            HeapSort(arr);
            assert(arr == std::vector<int>({1, 3, 7, 20}));

            std::cout << "All tests passed" << std::endl;
        }
    }
}
