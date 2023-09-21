#include <iostream>
#include <vector>
#include <cassert>

#include "priority_queue.hpp"

namespace data_structures
{
    namespace binary_heap
    {
        template <typename Comparable>
        class MinHeap : public priority_queue::PriorityQueue<Comparable>
        {
        private:
            std::vector<Comparable> arr;

            int Parent(int idx) { return (idx - 1) / 2; }
            int Left(int idx) { return 2 * idx + 1; }
            int Right(int idx) { return 2 * idx + 2; }

            void PercolationUp(int idx)
            {
                while (arr[idx] < arr[Parent(idx)] && idx > 0)
                {
                    std::swap(arr[idx], arr[Parent(idx)]);
                    idx = Parent(idx);
                }
            }

            void PercolationDown(int idx)
            {
                int left = Left(idx);
                int right = Right(idx);

                if (left >= arr.size())
                    return;
                else if (right >= arr.size())
                {
                    if (arr[idx] > arr[left])
                    {
                        std::swap(arr[idx], arr[left]);
                        PercolationDown(left);
                    }
                }
                else
                {
                    int min_child_idx = arr[left] <= arr[right] ? left : right;

                    if (arr[idx] > arr[min_child_idx])
                    {
                        std::swap(arr[idx], arr[min_child_idx]);
                        PercolationDown(min_child_idx);
                    }
                }
            }

        public:
            void Insert(Comparable element)
            {
                arr.push_back(element);
                PercolationUp(arr.size() - 1);
            }

            Comparable ExtractMin()
            {
                Comparable min = arr[0];
                std::swap(arr[0], arr[arr.size() - 1]);
                arr.pop_back();
                PercolationDown(0);

                return min;
            }
        };

        void TestMinHeap()
        {
            MinHeap<int> heap;
            heap.Insert(5);
            heap.Insert(3);
            heap.Insert(1);
            heap.Insert(2);

            assert(heap.ExtractMin() == 1);
            assert(heap.ExtractMin() == 2);
            assert(heap.ExtractMin() == 3);
            assert(heap.ExtractMin() == 5);

            std::cout << "All tests passed" << std::endl;
        }
    }
}
