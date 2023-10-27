from copy import deepcopy


class DisjointSet:
    def __init__(self):
        self.parents = {}
        self.height = {}

    def makeSet(self, x):
        self.parents[x] = x
        self.height[x] = 0

    def findSet(self, x):
        try:
            while x != self.parents[x]:
                x = self.parents[x]

            return x
        except KeyError:
            return None

    def unionSet(self, x, y):
        set_x = self.findSet(x)
        set_y = self.findSet(y)

        if set_x is None or set_y is None:
            return None

        if set_x == set_y:
            return set_x

        if self.height[set_x] <= self.height[set_y]:
            self.parents[set_x] = set_y
            if self.height[set_x] == self.height[set_y]:
                self.height[set_y] += 1
        else:
            self.parents[set_y] = set_x
