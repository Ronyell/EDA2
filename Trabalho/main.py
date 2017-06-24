from node import Node
from edge import Edge
from graph import Graph

nodes = []
nodes.append(Node(29, 'Pedro'))
nodes.append(Node(1, 'Maria'))
nodes.append(Node(99, 'Ana'))
nodes.append(Node(11, 'Marta'))
nodes.append(Node(23, 'Joao'))
nodes.append(Node(54, 'Mario'))
nodes.append(Node(51, 'Jorge'))
nodes.append(Node(77, 'Matheus'))
nodes.append(Node(88, 'Diego'))
nodes.append(Node(35, 'Meyhil'))
nodes.append(Node(18, 'Debora'))

edges = []
edges.append(Edge(nodes[0], nodes[1]))
edges.append(Edge(nodes[0], nodes[2]))
edges.append(Edge(nodes[1], nodes[3]))
edges.append(Edge(nodes[3], nodes[2]))
edges.append(Edge(nodes[5], nodes[1]))
edges.append(Edge(nodes[6], nodes[2]))
edges.append(Edge(nodes[7], nodes[4]))
edges.append(Edge(nodes[7], nodes[6]))
edges.append(Edge(nodes[2], nodes[1]))
edges.append(Edge(nodes[9], nodes[2]))
edges.append(Edge(nodes[10], nodes[4]))
edges.append(Edge(nodes[8], nodes[6]))
edges.append(Edge(nodes[10], nodes[5]))
edges.append(Edge(nodes[9], nodes[8]))


graph = Graph()

for node in nodes:
    graph.add_node(node)

for edge in edges:
    graph.add_edge(edge)

graph.plot_graph()
