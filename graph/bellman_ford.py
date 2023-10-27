import os, sys
from typing import List, Dict

sys.path.append(".." + os.path.sep + "data_structures")
from graph import WeightedGraph


# Leetcode 743. Network Delay Time

# You are given a network of n nodes, labeled from 1 to n.
# You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
# where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

# We will send a signal from a given node k.
# Return the minimum time it takes for all the n nodes to receive the signal.
# If it is impossible for all the n nodes to receive the signal, return -1.


# O(V*E)
def bellman_ford_efficient(
    weighted_graph: WeightedGraph, source: int
) -> List[Dict[int, int]]:
    weights = weighted_graph.weights
    distances = {vertex: float("inf") for vertex in weighted_graph.vertices}
    distances[source] = 0
    parents = {}

    changed_vertices = set([source])
    for _ in range(len(weighted_graph.vertices) - 1):
        for vertex in weighted_graph.vertices:
            if vertex in changed_vertices:
                changed_vertices.remove(vertex)
                for neighbour in weighted_graph.edges[vertex]:
                    edge = (vertex, neighbour)
                    # Relax(vertex, neighbour)
                    if distances[vertex] + weights[edge] < distances[neighbour]:
                        distances[neighbour] = distances[vertex] + weights[edge]
                        parents[neighbour] = vertex
                        changed_vertices.add(neighbour)

    return [distances, parents]


# O(V*E)
def bellman_ford_naive(
    weighted_graph: WeightedGraph, source: int
) -> List[Dict[int, int]]:
    weights = weighted_graph.weights
    distances = {vertex: float("inf") for vertex in weighted_graph.vertices}
    distances[source] = 0
    parents = {}

    for _ in range(len(weighted_graph.vertices) - 1):
        for vertex, neighbours in weighted_graph.edges.items():
            for neighbour in neighbours:
                edge = (vertex, neighbour)
                # Relax(vertex, neighbour)
                if distances[vertex] + weights[edge] < distances[neighbour]:
                    distances[neighbour] = distances[vertex] + weights[edge]
                    parents[neighbour] = vertex

    return [distances, parents]


def networkDelayTime(times: List[List[int]], n: int, k: int) -> int:
    weighted_graph = WeightedGraph(times)
    for vertex in range(1, n + 1):
        weighted_graph.vertices.add(vertex)
    distances, _ = bellman_ford_efficient(weighted_graph, k)

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
