import os, sys
from typing import List, Dict
from heapdict import heapdict

sys.path.append(".." + os.path.sep + "data_structures")
from graph import WeightedGraph


# Leetcode 743. Network Delay Time

# You are given a network of n nodes, labeled from 1 to n.
# You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
# where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

# We will send a signal from a given node k.
# Return the minimum time it takes for all the n nodes to receive the signal.
# If it is impossible for all the n nodes to receive the signal, return -1.


# O(ElogV)
def dijkstra_algorithm(
    weighted_graph: WeightedGraph, source: int
) -> List[Dict[int, int]]:
    heap = heapdict()
    for vertex in weighted_graph.vertices:
        heap[vertex] = float("inf")
    heap[source] = 0

    weights = weighted_graph.weights
    distances = {}
    parents = {}

    while len(heap) > 0:
        node, distance = heap.popitem()
        distances[node] = distance

        for neighbour in weighted_graph.edges[node]:
            if neighbour in heap:
                edge = (node, neighbour)
                parents[neighbour] = node
                heap[neighbour] = min(heap[neighbour], distance + weights[edge])

    return [distances, parents]


def networkDelayTime(times: List[List[int]], n: int, k: int) -> int:
    weighted_graph = WeightedGraph(times)
    for vertex in range(1, n + 1):
        weighted_graph.vertices.add(vertex)
    distances, _ = dijkstra_algorithm(weighted_graph, k)

    max_distance = max(distances.values())
    return max_distance if max_distance != float("inf") else -1


times = [[2, 1, 1], [2, 3, 1], [3, 4, 1]]
n = 4
k = 2
assert networkDelayTime(times, n, k) == 2

times = [[1, 2, 1]]
n = 2
k = 1
assert networkDelayTime(times, n, k) == 1

times = [[1, 2, 1]]
n = 2
k = 2
assert networkDelayTime(times, n, k) == -1

print("All tests passed!")
