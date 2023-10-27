import os, sys

sys.path.append(".." + os.path.sep + "data_structures")
from graph import Graph


def dfs(graph, vertex, visited=set()):
    visited.add(vertex)
    print(vertex, end=" ")

    for neighbor in graph.edges[vertex]:
        if neighbor not in visited:
            visited.add(neighbor)
            dfs(graph, neighbor)


graph = Graph([(1, 3), (1, 2), (2, 4), (3, 4), (4, 5), (4, 6), (5, 6)])
dfs(graph, 1)
