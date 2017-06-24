class Node:

    def __init__(self, key, info, neighbours=None):
        self.key = key
        self.info = info
        if neighbours is None:
            neighbours = []
        self.neighbours = neighbours

    def add_neighbour(self, node):
        self.neighbours.append(node)
