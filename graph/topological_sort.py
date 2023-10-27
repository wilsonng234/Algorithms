import os, sys
from typing import List
from collections import deque

sys.path.append(".." + os.path.sep + "data_structures")
from graph import Graph

# Leetcode 207. Course Schedule

# There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
# You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

# Return true if you can finish all courses. Otherwise, return false.


def canFinish(numCourses: int, prerequisites: List[List[int]]) -> bool:
    graph = Graph()

    for vertex in range(numCourses):
        graph.vertices.add(vertex)
    for prerequisite in prerequisites:
        graph.addEdge(prerequisite[1], prerequisite[0])

    indegree = {vertex: 0 for vertex in graph.vertices}

    for vertex, neighbours in graph.edges.items():
        for neighbour in neighbours:
            indegree[neighbour] += 1

    queue = deque([vertex for vertex in graph.vertices if indegree[vertex] == 0])
    topologicalOrdering = []

    while len(queue) > 0:
        vertex = queue.popleft()
        topologicalOrdering.append(vertex)

        for neighbour in graph.edges[vertex]:
            indegree[neighbour] -= 1
            if indegree[neighbour] == 0:
                queue.append(neighbour)

    return [indegree for indegree in indegree.values()].count(0) == len(graph.vertices)


numCourses = 2
prerequisites = [[1, 0]]
assert canFinish(numCourses, prerequisites) == True

numCourses = 2
prerequisites = [[1, 0], [0, 1]]
assert canFinish(numCourses, prerequisites) == False

print("All tests passed!")
