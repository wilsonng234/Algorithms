from typing import List
from collections import deque

# Leetcode 785. Is Graph Bipartite?

# There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v.
# The graph has the following properties:

# There are no self-edges (graph[u] does not contain u).
# There are no parallel edges (graph[u] does not contain duplicate values).
# If v is in graph[u], then u is in graph[v] (the graph is undirected).
# The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
# A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

# Return true if and only if it is bipartite.


def isBipartite(graph: List[List[int]]) -> bool:
    queue = deque()
    numVisited = 0
    visited = [False] * len(graph)
    grouping = [None] * len(graph)

    while numVisited < len(graph):
        root = visited.index(False)
        queue.append(root)
        visited[root] = True
        numVisited += 1

        while len(queue) > 0:
            node = queue.popleft()
            if grouping[node] is None:
                grouping[node] = 0
            group = grouping[node]

            for neighbour in graph[node]:
                if grouping[neighbour] == group:
                    return False

                if not visited[neighbour]:
                    visited[neighbour] = True
                    numVisited += 1
                    grouping[neighbour] = (group + 1) % 2
                    queue.append(neighbour)

    return True


graph = [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]
assert isBipartite(graph) == False

graph = [[1, 3], [0, 2], [1, 3], [0, 2]]
assert isBipartite(graph) == True

print("All tests passed!")
