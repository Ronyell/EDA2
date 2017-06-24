class Node:

    def __init__(self, key, info, nodes=None):
        self.key = key
        self.info = info
        if nodes is None:
            nodes = []
        self.nodes = nodes

    def add_node(self, node):
        self.nodes.append(node)
