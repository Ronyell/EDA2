import igraph

from edge import Edge
# from node import Node


class Graph:

    def __init__(self, nodes=None, edges=None):
        if nodes is None:
            self.nodes = []
        else:
            self.nodes = nodes

        if edges is None:
            self.edges = []
        else:
            self.edges = edges

    def add_node(self, node):
        self.nodes.append(node)

    def add_edge(self, edge):
        self.adges.append(edge)

    def plot_graph(self):
        graph_plot = igraph.Graph()
        graph_plot.add_vertices(self.V)

        k = 0
        for v in self.adj:
            for n in v:
                for i in range(len(v)):
                    graph_plot.add_edges([(k, self.adj[k][i])])
            k += 1

        layout = graph_plot.layout("kk")
        igraph.plot(graph_plot, layout=layout, margin=20)
