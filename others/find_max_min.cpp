#include <iostream>
#include <tuple>
#include <vector>
#include <cassert>

namespace others
{
    namespace find_max_min
    {
        // Time complexity: O(n) : 3*(n-1)/2
        std::tuple<int, int> FindMaxMin(const std::vector<int> &array)
        {
            if (array.empty())
                throw std::invalid_argument("array is empty");

            int i = 1;
            int max = array[0];
            int min = array[0];

            while (i < array.size())
            {
                if (array[i] > array[i + 1])
                {
                    if (array[i] > max)
                        max = array[i];
                    if (array[i + 1] < min)
                        min = array[i + 1];
                }
                else
                {
                    if (array[i + 1] > max)
                        max = array[i + 1];
                    if (array[i] < min)
                        min = array[i];
                }

                i += 2;
            }

            if (i % 2)
            {
                if (array[i] > max)
                    max = array[i];
                else if (array[i] < min)
                    min = array[i];
            }

            return std::make_tuple(max, min);
        }

        void Test()
        {
            int max, min;
            std::vector<int> array = {11, -2, -3, 0, 1, -7, -26};
            std::tie(max, min) = FindMaxMin(array);
            assert(max == 11 && min == -26);

            array.push_back(100);
            std::tie(max, min) = FindMaxMin(array);
            assert(max == 100 && min == -26);

            std::cout << "All tests passed" << std::endl;
        }
    }
}
