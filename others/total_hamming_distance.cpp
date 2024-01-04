#include <iostream>
#include <vector>
#include <cassert>

namespace others
{
    namespace total_hamming_distance
    {
        /*
            477. Total Hamming Distance

            The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
            Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.
        */

        int totalHammingDistance(std::vector<int> &nums)
        {
            int dist = 0;

            for (int i = 0; i < 32; i++)
            {
                int num_zeros = 0;
                int num_ones = 0;
                for (int num : nums)
                {
                    int num_last_bit = (num >> i) & 1;

                    if (num_last_bit == 0)
                        num_zeros += 1;
                    else
                        num_ones += 1;
                }

                dist += num_zeros * num_ones;
            }

            return dist;
        }

        void Test()
        {
            std::vector<int> nums = {4, 14, 2};
            assert(totalHammingDistance(nums) == 6);

            nums = {4, 14, 4};
            assert(totalHammingDistance(nums) == 4);

            std::cout << "All tests passed" << std::endl;
        }
    }
}
