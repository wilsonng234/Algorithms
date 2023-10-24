from graph import Graph


# Given an undirected graph check if it contains a cycle.
def cycle_detect(graph):
    visited = graph.visited = set()
    parents = graph.parents = {}
    vertices = graph.vertices
    edges = graph.edges

    def dfs(vertex):
        for neighbour in edges[vertex]:
            # tree edge
            if neighbour not in visited:
                visited.add(neighbour)
                parents[neighbour] = vertex
                if dfs(neighbour) == True:
                    return True
            # back edge
            elif parents[vertex] is not None and parents[vertex] != neighbour:
                return True

        return False

    for vertex in vertices:
        if vertex not in graph.visited:
            visited.add(vertex)
            parents[vertex] = None

            if dfs(vertex) == True:
                return True

    return False


graph = Graph([(1, 2), (2, 1), (2, 3), (3, 2)])
assert cycle_detect(graph) == False

graph = Graph([(1, 2), (2, 1), (2, 3), (3, 2), (1, 3), (3, 1)])
assert cycle_detect(graph) == True
