from person import Person
from edge import Edge
from graph import Graph


def menu(graph):
    option = 1
    while option is not 0:
        option = input(
            "Menu \n1 - Criar Pessoa \n2 - Criar Aresta \n3 - Verificar Conexao \n4 - Recomendar Amigo \n0 - Sair\n")
        if option is 0:
            print("Sair")
        elif option is 1:
            print("Criar Pessoa")
            graph.create_node()
        elif option is 2:
            print("Criar Aresta")
            graph.create_edge()
        elif option is 3:
            print("Verificar Conexao")
            graph.connected()
        elif option is 4:
            print("Recomendar Amigo")
            key = input("Entre com a chave: ")
            node_start = [node for node in graph.nodes if node.key == key]
            try:
                graph.recommend_friend(node_start[0])
            except IndexError:
                print("Chave inexistente!")
                option = 1
        else:
            print("Entrada invalida!")


people = []
people.append(Person(29, 'Pedro', 'm'))
people.append(Person(1, 'Maria', 'f'))
people.append(Person(99, 'Ana', 'f'))
people.append(Person(11, 'Marta', 'f'))
people.append(Person(23, 'Joao', 'm'))
people.append(Person(54, 'Mario', 'm'))
people.append(Person(51, 'Jorge', 'm'))
people.append(Person(77, 'Matheus', 'm'))
people.append(Person(88, 'Diego', 'm'))
people.append(Person(35, 'Meyhil', 'f'))
people.append(Person(18, 'Debora', 'f'))
people.append(Person(12, 'Lara', 'f'))
people.append(Person(144, 'Lord', 'f'))

edges = []
edges.append(Edge(people[0], people[1]))
edges.append(Edge(people[0], people[2]))
edges.append(Edge(people[1], people[3]))
edges.append(Edge(people[3], people[2]))
edges.append(Edge(people[5], people[1]))
edges.append(Edge(people[6], people[2]))
edges.append(Edge(people[7], people[4]))
edges.append(Edge(people[7], people[6]))
edges.append(Edge(people[2], people[1]))
edges.append(Edge(people[9], people[2]))
edges.append(Edge(people[10], people[4]))
edges.append(Edge(people[8], people[6]))
edges.append(Edge(people[10], people[5]))
edges.append(Edge(people[4], people[8]))
edges.append(Edge(people[10], people[8]))
edges.append(Edge(people[11], people[8]))
edges.append(Edge(people[11], people[7]))
edges.append(Edge(people[7], people[9]))
edges.append(Edge(people[10], people[12]))
edges.append(Edge(people[11], people[12]))

graph = Graph()

for node in people:
    graph.add_node(node)

for edge in edges:
    graph.add_edge(edge)

menu(graph)
