# Resposta A: Como e um algoritmo ambicioso temos que ele nao volta atras da decisao, toma decisoes locais
# para uma resposta global. Nessa caso caso colocassemos 5 7 3 a resposta desse algoritmo seria 7 enquanto o maior
# seria 5 + 3 = 8
#
# Resposta B: Como o algoritmo pega cada no saltando de 1 em 1 temos que dado um sequencia 7 5 3 4
# A resposta dada seria 7 + 3 = 10  enquanto a resposta correta seria 7 + 4 = 11


def maxWeight(values, valuesSum, quantity):
    if quantity == 0:
        return 0

    for i in range(0, quantity):
        valuesSum[i] = max(valuesSum[i-1], values[i] + valuesSum[i - 2])

    return valuesSum[quantity - 1]

values = [10, 11, 4, 18, 33]
quantity = len(values)
valuesSum = [0] * quantity

max_weight = maxWeight(values, valuesSum, quantity)
print('Partial weight: ' + str(valuesSum))
print('Max weight: ' + str(max_weight))
