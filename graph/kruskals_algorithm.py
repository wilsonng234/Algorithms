import os, sys
from typing import List

sys.path.append(".." + os.path.sep + "data_structures")
from graph import WeightedGraph
from disjoint_set import DisjointSet


# Leetcode 1584. Min Cost to Connect All Points

# You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

# The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

# Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.


# O(E log E + E log V) = O(E log V)
def kruskals_algorithm(graph: WeightedGraph) -> int:
    disjointSet = DisjointSet()
    for vertex in graph.vertices:
        disjointSet.makeSet(vertex)

    edges = []
    for vertex, neighbours in graph.edges.items():
        for neighbour in neighbours:
            edges.append((graph.weights[(vertex, neighbour)], vertex, neighbour))
    edges.sort()

    total_weight = 0
    for weight, vertex, neighbour in edges:
        if disjointSet.findSet(vertex) == disjointSet.findSet(neighbour):
            continue
        disjointSet.unionSet(vertex, neighbour)
        total_weight += weight

    return total_weight


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

    return kruskals_algorithm(weighted_graph)


points = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
assert minCostConnectPoints(points) == 20

points = [[3, 12], [-2, 5], [-4, 1]]
assert minCostConnectPoints(points) == 18

print("All tests passed!")
