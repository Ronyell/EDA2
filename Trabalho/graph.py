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
        self.visit = []

    def add_node(self, node):
        self.nodes.append(node)

    def add_edge(self, edge):
        self.edges.append(edge)

    def dfs(self, start):
        self.visit.append(start)
        self.count += 1
        print(start)

        for node in start.neighbours:
            if node not in self.visit:
                self.dfs(node)

    def connected(self):
        self.count = 0
        self.dfs(self.nodes[0])

        if self.count == len(self.nodes):
            print("Conectado")
        else:
            print("Nao conectado")

    def plot_graph(self):
        graph_plot = igraph.Graph(directed=False)

        lenght = len(self.nodes)
        graph_plot.add_vertices(lenght)

        number = 0
        for edge in self.edges:
            number = edge.source.set_number(number)
            number = edge.target.set_number(number)
            graph_plot.add_edges([(edge.source.number, edge.target.number)])
            graph_plot.vs[edge.source.number]["info"] = edge.source.info
            graph_plot.vs[edge.target.number]["info"] = edge.target.info
            graph_plot.vs[edge.source.number]["gender"] = edge.source.gender
            graph_plot.vs[edge.target.number]["gender"] = edge.target.gender

        color_dict = {"m": "blue", "f": "red"}
        graph_plot.to_directed()
        graph_plot.vs["color"] = [color_dict[gender] for gender in graph_plot.vs["gender"]]
        graph_plot.vs["label"] = graph_plot.vs["info"]
        layout = graph_plot.layout_kamada_kawai()
        igraph.plot(graph_plot, layout=layout, margin=70)
