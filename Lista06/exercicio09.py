# Resposta A: Dado a tabela
# |   | 01 | 02 | 03 | 04 | 05 |
# | x | 10 | 08 | 07 | 04 | 02 |
# | s | 09 | 07 | 05 | 03 | 01 |
# Caso  nao seja reiniciado temos 9 + 7 + 5 + 3 + 1 = 25
# Isso e o maximo que o computador pode processar caso ele seja reiniciado
# ele perdera processamento.


def maxPlan(values, allSum, quantity):
    if quantity == 0:
        return 0

    for i in range(1, quantity + 1):
        for j in range(1, quantity + 1):
            if j > i:
                # print(str(i) + ' ' + str(j) + ' ' + str(allSum[i][j - 1]))
                allSum[i][j] = allSum[i][j - 1]
                # print(allSum)
            else:
                allSum[i][j] = max(min(values[i - 1][0], values[i - 1][1]) + allSum[i][j - 1], allSum[i - 1][j])

    return allSum[quantity][quantity]

values = [[10, 8], [1, 4], [7, 2], [7, 1]]
quantity = len(values)
allSum = [(quantity + 1)*[0] for count in range(quantity + 1)]


optimalPlan = maxPlan(values, allSum, quantity)
print('Partial plans: ' + str(allSum))
print('Value of an optimal plan: ' + str(optimalPlan))
