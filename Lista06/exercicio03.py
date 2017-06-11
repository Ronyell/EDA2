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


def max_lenght(graph, lenght):
    # caminho = lenght*[0]
    result_numbers = [0] * (1+lenght)

    for position in graph:
        aux_result = -1
        for node in graph[position]:
            if result_numbers[node] != -1:
                if aux_result < (result_numbers[node] + 1):
                    aux_result = result_numbers[node] + 1

        result_numbers[position] = aux_result

    print(str(result_numbers))

    # for position in graph:
    #     print(str(position))
    #     for node in graph[position]:
    #         print(str(node))

graph = {
  1: [2, 3],
  2: [5],
  3: [4],
  4: [5],
  5: []
}

lenght = len(graph)
max_lenght(graph, lenght)
