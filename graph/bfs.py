from graph import Graph
from collections import deque


def bfs(root, graph):
    queue = deque([root])
    visited = set([root])
    distance = 0

    while len(queue) != 0:
        node = queue.popleft()

        for neighbor in graph.edges[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

                print(f"Node {neighbor} is at distance {distance+1} from root {root}")

        distance = distance + 1


graph = Graph()
edges = [[1, 2], [3, 0], [3, 1], [2, 3], [3, 6]]
for edge in edges:
    graph.addEdge(edge[0], edge[1])

bfs(1, graph)
