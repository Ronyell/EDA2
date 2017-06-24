from node import Node
from edge import Edge
from graph import Graph

node0 = Node(0, 'Noob0')
node1 = Node(1, 'Noob1')
edge = Edge(node0, node1)
print(node0.neighbours)
graph = Graph()
graph.add_node(node0)
graph.add_node(node1)
print(node0.neighbours)
node0.add_neighbour(node1)

for node_adjacent in graph.nodes:
    for node in node_adjacent.neighbours:
        print(node.info)
