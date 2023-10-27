from collections import defaultdict


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
