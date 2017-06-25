from person import Person
from edge import Edge

import igraph
import operator
from collections import deque


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

    def add_edge(self, edge):
        self.edges.append(edge)

    def add_node(self, node):
        self.nodes.append(node)

    def create_edge(self):
        key_1 = input("Entre com a chave da primeira pessoa: ")
        key_2 = input("Entre com a chave da segunda pessoa: ")
        first_node = [node for node in self.nodes if node.key == key_1]
        second_node = [node for node in self.nodes if node.key == key_2]
        try:
            edge = Edge(first_node[0], second_node[0])
            self.add_edge(edge)
        except IndexError:
            print("Alguma das chaves nao existe!")

    def create_node(self):
        key = input("Entre com a chave: ")
        key_exist = [node for node in self.nodes if node.key == key]
        while key_exist:
            key = input("A Chave digitada ja existe, entre com a chave novamente: ")
            key_exist = [node for node in self.nodes if node.key == key]

        name = raw_input("Entre com o nome: ")
        gender = raw_input("Entre com o genero: ")
        node = Person(key, name, gender)
        self.nodes.append(node)

    def dfs(self, start):
        self.visit.append(start)
        self.count += 1

        for node in start.neighbours:
            if node not in self.visit:
                self.dfs(node)

    def bfs(self, start):
        queue = deque()
        explored = []
        queue.append(start)

        while queue:
            node = queue.popleft()
            print(node)
            if node not in explored:
                explored.append(node)
                for node_explored in node.neighbours:
                    if node_explored not in explored and node_explored not in queue:
                        queue.append(node_explored)

    def connected(self):
        self.count = 0
        self.dfs(self.nodes[0])

        if self.count == len(self.nodes):
            print("Conectado")
        else:
            print("Nao conectado")

        self.visit = []

    def recommend_friend(self, node):
        common_friends = dict()
        for neighbour in node.neighbours:
            for neighbour_of_neighbour in neighbour.neighbours:
                if neighbour_of_neighbour not in node.neighbours and neighbour_of_neighbour is not node:
                    try:
                        common_friends[neighbour_of_neighbour] += 1
                    except KeyError:
                        common_friends[neighbour_of_neighbour] = 1
                else:
                    # Nothing to do
                    pass
            common_friends[neighbour] = None

        recommend_node = (
            max(common_friends.iteritems(), key=operator.itemgetter(1))[0])
        self.plot_graph_recommend(node, recommend_node, common_friends)

    def plot_graph(self):
        graph_plot = igraph.Graph(directed=True)

        lenght = len(self.nodes)
        graph_plot.add_vertices(lenght)

        number = 0
        for node in self.nodes:
            number = node.set_number(number)
            for neighbour in node.neighbours:
                number = neighbour.set_number(number)
                graph_plot.add_edges([(node.number, neighbour.number)])
            graph_plot.vs[node.number]["info"] = node.name
            graph_plot.vs[node.number]["gender"] = node.gender

        graph_plot.to_undirected()
        color_dict = {"m": "blue", "f": "red"}
        graph_plot.vs["color"] = [color_dict[gender]
                                  for gender in graph_plot.vs["gender"]]
        graph_plot.vs["label"] = graph_plot.vs["info"]
        layout = graph_plot.layout_kamada_kawai()
        igraph.plot(graph_plot, layout=layout, margin=70)

    def plot_graph_recommend(self, node_start, node_recommend, common_friends):
        graph_plot = igraph.Graph(directed=True)

        lenght = len(self.nodes)
        graph_plot.add_vertices(lenght)

        number = 0
        for node in self.nodes:
            number = node.set_number(number)
            for neighbour in node.neighbours:
                number = neighbour.set_number(number)
                graph_plot.add_edges([(node.number, neighbour.number)])
            try:
                if common_friends[node] is not None:
                    graph_plot.vs[node.number]["info"] = node.name + \
                        "\n" + str(common_friends[node])
                else:
                    graph_plot.vs[node.number]["info"] = node.name
            except KeyError:
                graph_plot.vs[node.number]["info"] = node.name + "\n" + str(0)

            if node is node_start:
                graph_plot.vs[node.number]["color"] = "green"
                graph_plot.vs[node.number]["info"] = node.name
            elif node is node_recommend and common_friends[node] is not None:
                graph_plot.vs[node.number]["color"] = "blue"

        graph_plot.to_undirected()
        graph_plot.vs["label"] = graph_plot.vs["info"]
        layout = graph_plot.layout_kamada_kawai()
        igraph.plot(graph_plot, layout=layout, margin=70)
