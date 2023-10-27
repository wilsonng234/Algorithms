from collections import defaultdict


def getAdjacencyMatrix(adjacencyList, weights):
    num_vertices = max(adjacencyList.keys()) + 1
    adjacencyMatrix = [[0 for _ in range(num_vertices)] for _ in range(num_vertices)]

    for vertex, neighbours in adjacencyList.items():
        for neighbour in neighbours:
            adjacencyMatrix[vertex][neighbour] = weights[(vertex, neighbour)]


class Graph:
    def __init__(self, edges=[]):
        self.vertices = set()
        self.edges = defaultdict(set)

        for edge in edges:
            self.addEdge(edge[0], edge[1])

    def addEdge(self, u, v):
        self.vertices.add(u)
        self.vertices.add(v)
        self.edges[u].add(v)


class WeightedGraph:
    def __init__(self, edges=[]):
        self.vertices = set()
        self.edges = defaultdict(set)
        self.weights = defaultdict(int)

        for edge in edges:
            self.addEdge(edge[0], edge[1], edge[2])

    def addEdge(self, u, v, weight):
        self.vertices.add(u)
        self.vertices.add(v)
        self.edges[u].add(v)
        self.weights[(u, v)] = weight
