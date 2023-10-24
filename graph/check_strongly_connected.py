import random
from collections import deque


def reversed_edges(edges):
    return [(edge[1], edge[0]) for edge in edges]


# 1. If  graph G has a strong vertex s then EVERY vertex in G is strong
# 2. A graph G is strongly connected if and only if every vertex in G is strong
def check_reached_all_nodes(nodes, edges, root):
    visited = set()
    queue = deque([root])

    while queue:
        node = queue.popleft()
        visited.add(node)

        for edge in edges:
            if edge[0] == node and edge[1] not in visited:
                queue.append(edge[1])

    return visited == nodes


def check_strongly_connected(edges):
    nodes = set()
    for edge in edges:
        nodes.add(edge[0])
        nodes.add(edge[1])

    s = random.choice(list(nodes))
    can_reach_all_nodes = check_reached_all_nodes(nodes, edges, s)
    can_be_reached_from_all_nodes = check_reached_all_nodes(
        nodes, reversed_edges(edges), s
    )

    return can_reach_all_nodes and can_be_reached_from_all_nodes


edges = [(0, 1), (1, 2), (2, 3), (3, 0), (2, 4), (4, 2)]
assert check_strongly_connected(edges) == True

edges = [(0, 1), (1, 2), (2, 3)]
assert check_strongly_connected(edges) == False
