class Graph:

    def __init__(self, nodes=None, edges=None):
        if nodes is None:
            nodes = []
        else:
            self.nodes = nodes

        if edges is None:
            edges = []
        else:
            self.edges = edges

    def add_node(self, node):
        self.nodes.append(node)

    def add_edge(self, edge):
        self.adges.append(edge)
