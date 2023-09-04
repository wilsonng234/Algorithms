#include <iostream>
#include <vector>

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

int main()
{
    std::vector<int> arr = {5, -2, 4, -6, 1, 3};
    InsertionSort(arr);

    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
}
