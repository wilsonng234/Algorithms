#include <iostream>
#include <vector>
#include <cassert>

namespace divide_and_conquer
{
    namespace the_skyline_problem
    {
        void AddPoint(std::vector<std::vector<int>> &merged_skyline, std::vector<int> point)
        {
            if (merged_skyline.empty())
            {
                merged_skyline.push_back(point);
            }
            else if (point[0] != merged_skyline[merged_skyline.size() - 1][0] && point[1] != merged_skyline[merged_skyline.size() - 1][1])
            {
                merged_skyline.push_back(point);
            }
            else if (point[0] == merged_skyline[merged_skyline.size() - 1][0])
            {
                merged_skyline[merged_skyline.size() - 1][1] = point[1];
            }
        }

        std::vector<std::vector<int>> MergeSkyline(const std::vector<std::vector<int>> &left, const std::vector<std::vector<int>> &right)
        {
            int i = 0, j = 0;
            int leftY = 0, rightY = 0;
            std::vector<std::vector<int>> merged_skyline;

            while (i < left.size() && j < right.size())
            {
                if (left[i][0] < right[j][0])
                {
                    AddPoint(merged_skyline, {left[i][0], std::max(left[i][1], rightY)});
                    leftY = left[i][1];
                    i++;
                }
                else if (left[i][0] > right[j][0])
                {
                    AddPoint(merged_skyline, {right[j][0], std::max(right[j][1], leftY)});
                    rightY = right[j][1];
                    j++;
                }
                else if (left[i][0] == right[j][0])
                {
                    AddPoint(merged_skyline, {left[i][0], std::max(left[i][1], right[j][1])});
                    leftY = left[i][1];
                    rightY = right[j][1];
                    i++;
                    j++;
                }
            }

            while (i < left.size())
                AddPoint(merged_skyline, left[i++]);
            while (j < right.size())
                AddPoint(merged_skyline, right[j++]);

            return merged_skyline;
        };

        std::vector<std::vector<int>> GetSkyline(const std::vector<std::vector<int>> &buildings, int start, int end);

        std::vector<std::vector<int>> GetSkyline(const std::vector<std::vector<int>> &buildings)
        {
            return GetSkyline(buildings, 0, buildings.size() - 1);
        }

        std::vector<std::vector<int>> GetSkyline(const std::vector<std::vector<int>> &buildings, int start, int end)
        {
            if (start == end)
            {
                std::vector<std::vector<int>> skyline;

                skyline.push_back({buildings[start][0], buildings[start][2]});
                skyline.push_back({buildings[start][1], 0});

                return skyline;
            }

            int mid = start + (end - start) / 2;
            std::vector<std::vector<int>> left = GetSkyline(buildings, start, mid);
            std::vector<std::vector<int>> right = GetSkyline(buildings, mid + 1, end);

            return MergeSkyline(left, right);
        }

        void Test()
        {
            std::vector<std::vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}};
            std::vector<std::vector<int>> skyline = GetSkyline(buildings);
            assert(skyline == std::vector<std::vector<int>>({{2, 10}, {3, 15}, {7, 10}, {9, 0}}));

            buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
            skyline = GetSkyline(buildings);
            assert(skyline == std::vector<std::vector<int>>({{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}}));

            buildings = {{2, 9, 10}, {5, 7, 15}, {5, 12, 12}, {5, 20, 10}, {19, 24, 8}};
            skyline = GetSkyline(buildings);
            assert(skyline == std::vector<std::vector<int>>({{2, 10}, {5, 15}, {7, 12}, {12, 10}, {20, 8}, {24, 0}}));

            std::cout << "All tests passed" << std::endl;
        }
    }
}
