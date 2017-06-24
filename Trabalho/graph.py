import igraph


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
        self.edges.append(edge)

    def plot_graph(self):
        graph_plot = igraph.Graph(directed=False)

        lenght = len(self.nodes)
        graph_plot.add_vertices(lenght)

        number = 0
        for node in self.nodes:
            number = node.set_number(number)
            for neighbour in node.neighbours:
                    number = neighbour.set_number(number)
                    graph_plot.add_edges([(node.number, neighbour.number)])
            graph_plot.vs[node.number]["info"] = node.info

        print(str(graph_plot.get_edgelist()))
        graph_plot.vs["label"] = graph_plot.vs["info"]
        layout = graph_plot.layout_kamada_kawai()
        igraph.plot(graph_plot, layout=layout, margin=20)
