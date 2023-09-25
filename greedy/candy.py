from typing import List
import math

# 135. Candy

# There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
# You are giving candies to these children subjected to the following requirements:
# - Each child must have at least one candy.
# - Children with a higher rating get more candies than their neighbors.

# Children with a higher rating get more candies than their neighbors.


def candy(ratings: List[int]) -> int:
    sorted_idxs = sorted(range(len(ratings)), key=lambda idx: ratings[idx])
    min_rating = ratings[sorted_idxs[0]]

    distributed_candies = {}
    num_candy = 0
    for idx in sorted_idxs:
        rating = ratings[idx]
        if rating == min_rating:
            distributed_candies[idx] = 1
            num_candy += 1
        else:
            left = math.inf if idx == 0 else ratings[idx - 1]
            right = math.inf if idx + 1 == len(sorted_idxs) else ratings[idx + 1]

            cur_candy = -math.inf
            if rating > left and distributed_candies.get(idx - 1):
                cur_candy = distributed_candies[idx - 1] + 1
            if rating > right and distributed_candies.get(idx + 1):
                cur_candy = max(cur_candy, distributed_candies[idx + 1] + 1)

            distributed_candies[idx] = 1 if math.isinf(cur_candy) else cur_candy
            num_candy += distributed_candies[idx]

    return num_candy


ratings = [1, 0, 2]
assert candy(ratings) == 5

ratings = [1, 2, 2]
assert candy(ratings) == 4

print("All tests passed!")
