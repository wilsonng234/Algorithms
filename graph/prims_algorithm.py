import os, sys
from typing import List
from heapdict import heapdict

sys.path.append(".." + os.path.sep + "data_structures")
from graph import WeightedGraph

# Leetcode 1584. Min Cost to Connect All Points

# You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

# The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

# Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.


# O(E log V)
def prims_algorithm(graph: WeightedGraph, start: int) -> int:
    heap = heapdict()
    for vertex in graph.vertices:
        heap[vertex] = float("inf")
    heap[start] = 0
    path_weight = 0

    while len(heap) > 0:
        vertex, weight = heap.popitem()
        path_weight += weight

        for neighbor in graph.edges[vertex]:
            # Decrease key
            if neighbor in heap:
                heap[neighbor] = min(heap[neighbor], graph.weights[(vertex, neighbor)])

    return path_weight


def minCostConnectPoints(points: List[List[int]]) -> int:
    weighted_graph = WeightedGraph()

    for i in range(len(points)):
        point1 = points[i]

        for j in range(len(points)):
            if i == j:
                continue
            point2 = points[j]

            manhattan_distance = abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])
            weighted_graph.addEdge(i, j, manhattan_distance)

    return prims_algorithm(weighted_graph, 0)


points = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
assert minCostConnectPoints(points) == 20

points = [[3, 12], [-2, 5], [-4, 1]]
assert minCostConnectPoints(points) == 18

print("All tests passed!")
