#include <iostream>
#include <vector>

int BinarySearch(const std::vector<int> &sorted_array, int target, int left, int right);

int BinarySearch(const std::vector<int> &sorted_array, int target)
{
    int left = 0;
    int right = sorted_array.size() - 1;

    return BinarySearch(sorted_array, target, left, right);
}

int BinarySearch(const std::vector<int> &sorted_array, int target, int left, int right)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;
    if (sorted_array[mid] == target)
        return mid;
    else if (sorted_array[mid] < target)
        return BinarySearch(sorted_array, target, mid + 1, right);
    else
        return BinarySearch(sorted_array, target, left, mid - 1);
}

int main()
{
    const std::vector<int> sorted_array = {-6, -2, 1, 3, 4, 5};
    std::cout << BinarySearch(sorted_array, -6) << std::endl;
    std::cout << BinarySearch(sorted_array, 1) << std::endl;
    std::cout << BinarySearch(sorted_array, 5) << std::endl;
    std::cout << BinarySearch(sorted_array, 0) << std::endl;

    return 0;
}