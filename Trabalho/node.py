

# Nothing.
class Node:

    def __init__(self, key, info, nodes=None):
        self.key = key
        self.info = info
        if nodes is None:
            nodes = []
        self.nodes = nodes
