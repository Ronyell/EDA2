#
# def encontra_caminho(grafo, inicio, fim, caminho=[]):
#     caminho += [inicio]
#
#     if inicio == fim:
#         return caminho
#     if inicio not in grafo:
#         return None
#     for aresta in grafo[inicio]:
#         if aresta not in caminho:
#             novo_caminho = encontra_caminho(grafo, aresta, fim, caminho)
#             if novo_caminho:
#                 return novo_caminho
#     return None
#
# grafo = {
#   '1': ['2', '3'],
#   '2': ['5'],
#   '3': ['4'],
#   '4': ['5'],
#   '5': []
# }
#
#
# print(str(encontra_caminho(grafo, '1', '5')))
#
#


def max_lenght(graph, start, way, end):
    lenght = 0
    way_partial = []

    for index, node in enumerate(graph[start]):
        if(lenght == 0):
            graph[start][index] = True
            lenght = lenght + 1
        else:
            lenght = lenght + 1
            way_partial.append(max_lenght(graph, node, way, end))
            way_partial.append(node)

    if not way_partial:
        end = start

    if len(way) < len(way_partial) and end in way_partial:
        way.append(start)

    print(str(graph[start]) + ' ' + str(way))

    return way_partial

    # for position in graph:
    #     print(str(position))
    #     for node in graph[position]:
    #         print(str(node))

graph = {
  1: [False, 2, 4],
  2: [False, 4, 5, 3],
  3: [False, 4],
  4: [False, 5],
  5: [False]
}

visit = [False] * len(graph)
way = []
end = 5
start = 1

lenght = len(graph)
for node in graph:
    if not graph[node][0]:
        max_lenght(graph, node, way, end)
