#include <iostream>
#include <vector>
#include <cassert>

namespace sorting
{
    namespace selection_sort
    {
        void SelectionSort(std::vector<int> &arr)
        {
            for (int i = 0; i < arr.size(); i++)
                for (int j = i + 1; j < arr.size(); j++)
                    if (arr[j] < arr[i])
                        std::swap(arr[i], arr[j]);
        }

        void Test()
        {
            std::vector<int> arr = {5, -2, 4, -6, 1, 3};
            SelectionSort(arr);

            assert(arr == std::vector<int>({-6, -2, 1, 3, 4, 5}));
            std::cout << "All tests passed" << std::endl;
        }
    }
}
