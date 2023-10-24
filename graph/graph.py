from collections import defaultdict


class Graph:
    def __init__(self):
        self.vertices = set()
        self.edges = defaultdict(set)

    def addEdge(self, u, v):
        self.vertices.add(u)
        self.vertices.add(v)
        self.edges[u].add(v)
