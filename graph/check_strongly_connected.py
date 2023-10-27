import os, sys, random
from collections import deque, defaultdict

sys.path.append(".." + os.path.sep + "data_structures")

from graph import Graph


def reversed_edges(edges):
    reversed_edges = defaultdict(set)
    for node, neighbors in edges.items():
        for neighbor in neighbors:
            reversed_edges[neighbor].add(node)

    return reversed_edges


# 1. If  graph G has a strong vertex s then EVERY vertex in G is strong
# 2. A graph G is strongly connected if and only if every vertex in G is strong
def check_reached_all_nodes(nodes, edges, root):
    visited = set()
    queue = deque([root])

    while queue:
        node = queue.popleft()
        visited.add(node)

        for node in nodes:
            for neighbor in edges[node]:
                if neighbor not in visited:
                    queue.append(neighbor)

    return visited == nodes


def check_strongly_connected(graph):
    s = random.choice(list(graph.vertices))
    can_reach_all_nodes = check_reached_all_nodes(graph.vertices, graph.edges, s)
    can_be_reached_from_all_nodes = check_reached_all_nodes(
        graph.vertices, reversed_edges(graph.edges), s
    )

    return can_reach_all_nodes and can_be_reached_from_all_nodes


graph = Graph()
edges = [(0, 1), (1, 2), (2, 3), (3, 0), (2, 4), (4, 2)]
for edge in edges:
    graph.addEdge(edge[0], edge[1])
assert check_strongly_connected(graph) == True


graph = Graph()
edges = [(0, 1), (1, 2), (2, 3)]
for edge in edges:
    graph.addEdge(edge[0], edge[1])
assert check_strongly_connected(graph) == False

print("All tests passed!")
