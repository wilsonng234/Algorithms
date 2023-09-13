#include <iostream>
#include <vector>
#include <cassert>

namespace insertion_sort
{
    void InsertionSort(std::vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            int j = i - 1;
            while (j >= 0 && arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                j--;
            }
        }
    }

    void Test()
    {
        std::vector<int> arr = {5, -2, 4, -6, 1, 3};
        InsertionSort(arr);

        assert(arr == std::vector<int>({-6, -2, 1, 3, 4, 5}));
        std::cout << "All tests passed" << std::endl;
    }
}
