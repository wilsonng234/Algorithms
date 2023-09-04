#include <iostream>
#include <vector>

void SelectionSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[i])
                std::swap(arr[i], arr[j]);
}

int main()
{
    std::vector<int> arr = {5, -2, 4, -6, 1, 3};
    SelectionSort(arr);

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
}
