from typing import List

# Leetcode 1710. Maximum Units on a Truck
# You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
# - numberOfBoxesi is the number of boxes of type i.
# - numberOfUnitsPerBoxi is the number of units in each box of the type i.

# You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
# Return the maximum total number of units that can be put on the truck.


def maximum_units(boxTypes: List[List[int]], truckSize: int) -> int:
    boxTypes.sort(key=lambda boxType: boxType[1], reverse=True)

    i = 0
    max_units = 0

    while truckSize > 0 and i < len(boxTypes):
        max_units += min(truckSize, boxTypes[i][0]) * boxTypes[i][1]
        truckSize -= boxTypes[i][0]
        i += 1

    return max_units


boxTypes = [[1, 3], [2, 2], [3, 1]]
truckSize = 4
assert maximum_units(boxTypes, truckSize) == 8

boxTypes = [[5, 10], [2, 5], [4, 7], [3, 9]]
truckSize = 10
assert maximum_units(boxTypes, truckSize) == 91

print("All tests passed!")
