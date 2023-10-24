from collections import deque


def bfs(root, edges):
    visited = [False] * len(edges)
    visited[root] = True

    queue = deque([root])
    distance = 0

    while len(queue) != 0:
        node = queue.popleft()

        for neighbor in edges[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

        print(f"Node {node} is at distance {distance} from root {root}")
        distance = distance + 1


bfs(0, [[1, 2], [3, 0], [3, 1], []])
